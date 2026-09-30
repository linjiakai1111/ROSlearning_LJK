#include<random>
#include<opencv2/opencv.hpp>
#include<cmath>
#include<iostream>
#include<vector>
#include<chrono>
//g++-13 convex_judge.cpp -o convex_judge $(pkg-config --cflags --libs opencv4)
using namespace std;
using namespace cv;

#define USING_HARRIS false
#define USING_CONVEX false

int GRN(int,int);
Mat Find_ConvexHull(Mat&,int,int,const std::vector<Point2f>&);
VideoCapture get_videoINFO(std::string,double&,int&,int&,int&);
// int video_cap(VideoCapture&,Mat&);

int main(){
  int frame_total = 0;
  int frame_count = 0;
  int height = 0;
  int width = 0;
  double fps;
  std::string video_path = "./cube01.mp4";
  Mat ori_img_src,img_src;
  Mat edge_img;
  VideoCapture cap = get_videoINFO(video_path,fps,height,width,frame_total);
  std::vector<Point2f> con_pts;
  Mat convex_back(Size(width,height),0,CV_8UC1);
  Mat corner_img = convex_back.clone();
  // Mat background(Size(width,height),0,CV_8UC1);
  std::vector<Vec4i> Hough_line;
  int rate = 1000/fps;


  if(!cap.isOpened()){
      cout << "视频打不开" << endl;
      return 0;
  }
  
  cout << video_path << "中共有" << frame_total << "张图片" << endl;
  while(true){
    auto start = std::chrono::steady_clock::now();
    try{
      cap >> ori_img_src;
    }catch(const cv::Exception& e){
      cerr << "图片为空" 
           << "共输出帧数：" << frame_count 
           << e.what();
      break;
    }
    //高斯滤波
    convex_back.setTo(Scalar(0));
    corner_img.setTo(Scalar(0));
    con_pts.clear();
    if(ori_img_src.empty()){
      cout << "图片为空\n" 
           << "共输出帧数：" << frame_count << endl;
      break;
    }
    GaussianBlur(ori_img_src, img_src, Size(0,0), 1.5);
    // Canny边缘检测
    Canny(
      img_src,
      edge_img,
      50,
      150
    );
    if(USING_HARRIS){
      cv::goodFeaturesToTrack(
        edge_img,
        con_pts,
        1000,
        0.01,
        10
      );\
      for(auto& pt:con_pts){
      circle(corner_img,pt,1,255,-1);
    }
    }
    else{
      HoughLinesP(edge_img,Hough_line,1,CV_PI/180,40,20,30);
      for(auto& l:Hough_line){
        Point pt1,pt2;
        pt1.x = l[0];
        pt1.y = l[1];
        pt2.x = l[2];
        pt2.y = l[3];
        circle(corner_img,pt1,3,255,-1);
        circle(corner_img,pt2,3,255,-1);
        con_pts.emplace_back(pt1);
        con_pts.emplace_back(pt2);
        line(
          corner_img,
          pt1,
          pt2,
          Scalar(255),
          1,
          LINE_AA,
          0
        );
      }
    }
    cout << "角点数：" << con_pts.size() << endl;
    if(con_pts.size()==0) continue;
    if(USING_CONVEX){
      convex_back = Find_ConvexHull(convex_back,height,width,con_pts);
      imshow("ConvexHull",convex_back);
    }
    cout << "第" << frame_count+1 << "帧" << endl;
    imshow("edge",edge_img);
    imshow("corner",corner_img);
    waitKey(rate);
    frame_count++;
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    cout << "性能：" << duration.count() << " ms" <<endl;
    cout << "--------" << endl;
  //Rect rect_poly(Point(),Point());
  }

  return 0;
}
int GRN(int min,int max){
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution dist(min,max);
  return dist(gen);
}
double line_pt_dist(double k,double b,Point pt){
  return abs(k*pt.x-pt.y+b)/sqrt(pow(k,2)+1);
}
Mat Find_ConvexHull(Mat& convex_back,int height,int width,const std::vector<Point2f>& con_pts){
  std::vector<Point2f> out_pts;
  convexHull(con_pts,out_pts);
  int count = 0;
  for(auto &pt:out_pts){
    circle(convex_back,pt,3,255,-1);
    count++;
  }
  std::cout << "凸包点数：" << count << endl;
  for(int i=0;i<out_pts.size();i++){
    Point2f start = out_pts.at(i);
    Point2f termination = (i==out_pts.size()-1) ? out_pts.front() : out_pts.at(i+1);
    line(
      convex_back,
      start,
      termination,
      Scalar(255),
      1,
      LINE_AA,
      0
    );
  }
  return convex_back;
}
VideoCapture get_videoINFO(std::string video_path,double& fps,int& height,int& width,int& frame_total){
    VideoCapture cap(video_path);
    fps = cap.get(CAP_PROP_FPS);
    height = cap.get(CAP_PROP_FRAME_HEIGHT);
    width = cap.get(CAP_PROP_FRAME_WIDTH);
    frame_total = cap.get(CAP_PROP_FRAME_COUNT);
    cout << "帧率:" << fps
         << "\nheight:" << height
         << "\nwidth:" << width
         << "\n总帧数:" << frame_total << endl;
    return cap;
}