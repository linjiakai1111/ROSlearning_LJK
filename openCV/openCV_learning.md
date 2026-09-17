# <center>openCV</center>
## ==01==-显示图像
```cpp
#include <opencv2/opencv.hpp>

int main(int argc,char ** argv)
{
  cv::Mat src = cv::imread("park.png",cv::IMREAD_GRAYSCALE);
  //cv::namedWindow("输入窗口",cv::WINDOW_FREERATIO);
  if(src.empty())
  {
    printf("Couldn't find image");
  }
  cv::imshow("Kalman_Filter",src);
  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
```
- `imread("/path/to/image")`读取指定路径下的图像，然后返回图像,且读图像时，**若未加任何读取类型，都会把读取到的图像转为CV_8UC1再输出
  常见读取类型:IMREAD_GRAYSCALE(读取为CV_8UC1),IMREAD_UNCHNAGED(保持不变)
- `imshow(string,image_src)`string:窗口名称；image_src:上面由imread得到的图像变量
- `waitKey()`指定图像显示时长(ms)
## ==02==-进行颜色空间转换
```cpp
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char ** argv){
  Mat gray,hsv;
  Mat src = imread("park.png");
  cvtColor(src,hsv,COLOR_BGR2HSV);
  cvtColor(src,gray,COLOR_BGR2GRAY);
  imshow("HSV",hsv);
  waitKey(0);
  imwrite("/home/line/ROSlearning_LJK/openCV/park_hsv.png",hsv);
  imshow("GRAY",gray);
  waitKey(0);
  imwrite("/home/line/ROSlearning_LJK/openCV/park_gray.png",gray);
  return 0;
}
```
- `cvtColor(param1,param2,SHIFT_TYPE)`pram1:原图像；param2:转换后的图像；转换形式:
1. COLOR_RBG2HSV:RBG->HSV
2. COLOR_RBG2GRAY:RBG->GRAY
```cpp
```
## ==03==-Mat的基本结构以及内部方法的使用
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;

int g_r_n();

int main(int argc,char ** argv){
  Mat src_0,src_1,src_2;
  src_0 = imread("park.png");
  src_1=src_0.clone();
  src_0.copyTo(src_2);
  imshow("param=image.clone()拷贝方法",src_1);
  imshow("image.copyTo(param)复制方法",src_2);
  waitKey(0);
  Mat matrix_C1=Mat::zeros(Size(8,8),CV_8UC1);
  Mat matrix_C3=Mat::zeros(Size(8,8),CV_8UC3);
  std::cout<< matrix_C1 << "\n" << 
  matrix_C3 << "\nheight:" << matrix_C3.cols <<
               "\twidth:"<< matrix_C3.rows <<
               "\tchannel:"<< matrix_C3.channels() 
               <<std::endl;
  Mat matrix_ones = Mat::ones(Size(4,4),CV_8UC1);
  Mat matrix_one_C3 = Mat::ones(Size(4,4),CV_8UC3);
  std::cout << matrix_ones << std::endl;
  std::cout << matrix_one_C3 << std::endl;
  matrix_one_C3 = Scalar(255,255,255);
  std::cout << matrix_one_C3 << std::endl;
  Mat random_matrix(Size(512,512),CV_8UC3,Scalar(g_r_n(),g_r_n(),g_r_n()));
  imshow("random_image_matrix",random_matrix);
  waitKey(0);
  return 0;
}
int g_r_n()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0,255);
  return dist(gen);
}
```
**Mat的结构：**
|matrix_header|data_point->real_memory_address|
|---|---|
1. **matrix_header**:储存矩阵的尺寸信息，通道数，数据类型(如CV_8UC3为3通道8位无符号整型,CV_32FC1为单通道32位浮点型)
2. **data_point**指向内存中实际存储矩阵变量的区域**real_memory_address**
- 直接使用`=`符号赋值时为浅拷贝，**matrix_header**和**data_point**都指向同一块内存区域，改变其中一个矩阵的值会影响另一个矩阵
- `param = image.clone()`返回Mat类型，克隆到param，必须是Mat类型，新分配内存
- `image.copyTo(param)`将image的内容复制到param中，param必须是Mat类型，新分配内存
- `Mat::zeros(Size(8,8),CV_8UC1)`创建一个8*8的单通道矩阵，所有元素初始化为0
- `Mat::ones(Size(8,8),CV_8UC1)`创建一个8*8的单通道矩阵，所有元素初始化为1(注意，当通道数不为1是，这个函数只会将第一个通道内的元素初始化为1)
- `param = Scalar(i,j,k)`Mat变量内部提供了收纳Scalar变量的构造函数，Scalar实际上可以理解为一个储存像素值的容器(最多可存4个值)，Mat可以在对应通道上接收Scalar提供的参数
- `Mat(Size(512,512),CV_8UC3,Scalar(g_r_n(),g_r_n(),g_r_n()))`创建一个512*512的三通道矩阵，并将每个像素点的值初始化为随机数
- `matrix.cols`矩阵的列数
- `matrix.rows`矩阵的行数
- `matrix.channels()`矩阵的通道数
### 这里顺带提一嘴**random**库
- std::random_device：一个从系统熵池中获取随机数种子类，例如定义rd为该类，rd()不是构造函数，而是一个函数重载运算符，用于返回随机种子
- std::mt19937：梅森旋转算法的随机数引擎，根据随机数种子获取随机数,当种子一样时，生成的随机数序列就完全相同，常用于复现实验
- std::uniform_int_distribution`<>`：它是一个分布器（Distribution），定义在 `<random>` 中。它的作用是将引擎产生的原始随机整数，映射到你指定的一个闭区间 [a, b] 内的整数，并且保证区间内每个整数被选中的概率是相等的（即均匀分布）
## ==04==-像素的读取与使用
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main(int argc,char ** argv)
{
  Mat src_park01=imread("park.png");
  Mat src_park02=src_park01.clone();
  int park_h = src_park01.rows;
  int park_w = src_park01.cols;
  int dims = src_park01.channels();
  std::cout << "height:" << park_h
       << "\nwidth:" << park_w
       << std::endl;
  //Mat自带at<>(y,x)方式读取与修改像素
  for(int h = 0 ;h < park_h ; h++)
    for(int w = 0 ;w < park_w ; w++)
    {
        if(dims == 1)
        {
          int pv = src_park01.at<uchar>(h,w);
          src_park01.at<uchar>(h,w) = 255 - pv;
        }
        if(dims == 3)
        {
          Vec3b bgr = src_park01.at<Vec3b>(h,w);
          src_park01.at<Vec3b>(h,w)[0] = 255 - bgr[0];
          src_park01.at<Vec3b>(h,w)[1] = 255 - bgr[1];
          src_park01.at<Vec3b>(h,w)[2] = 255 - bgr[2];
        }
    }
  //指针方式读取与修改像素
  for(int h = 0; h < park_h ; h++ ){
    uchar* current_row = src_park02.ptr<uchar>(h);
    for(int w = 0 ; w < park_w ; w++ )
    {
      if(dims == 1)
      {
        *current_row++ = 255 - *current_row;
      }
      if(dims == 3)
      {
        *current_row++ = 255 - *current_row;
        *current_row++ = 255 - *current_row;
        *current_row++ = 255 - *current_row;
      }
    }
  }
    imshow("Converted RGB src_park01",src_park01);
    waitKey(0);
    imshow("Converted RGB src_park02",src_park02);
    waitKey(0);
  return 0;
}
```
- Mat类中的at<>(rows,cols)是获取图像像素坐标的方法，<>中输入像素数据类型，()中为行列

|Mat类型|像素类型|图像类型|
|---|---|---|
|CV_8UC1|uchar|灰度图|
|CV_8UC3|Vec3b|RGB图|
|CV_8UC4|Vec4b|RGBA图|
|CV_32FC1|float|浮点单通道|
|CV_32FC3|Vec3f|浮点三通道|
|CV_64FC1|double|双精度单通道|
- 当使用多通道时，取出的at<>()是一个数组，通过[]进行取值和赋值
- 除了使用at<>(行,列)方法，还可以使用指针进行取值与赋值,获取指针的方法：`Mat_param.ptr<type>(row)`
## ==05==-Mat的运算
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
using namespace cv;
int g_r_n();
int main(int argc,char ** argv)
{
  Mat origin_src = imread("park.png");
  int height = origin_src.rows;
  int width = origin_src.cols;
  Mat dst_add,dst_subtract,dst_multiply,dst_divide;
  Mat random_Matrix(Size(width,height),CV_8UC3,Scalar(g_r_n(),g_r_n(),g_r_n()));
  /*直接加减的模式
  imshow("light enhanced origin_src",origin_src+random_Matrix);
  waitKey(0);
  imshow("light diminished origin_src",origin_src-Scalar(g_r_n(),g_r_n(),g_r_n()));
  waitKey(0);
  */
  //使用openCV内置函数的模式
  //加法
  add(origin_src,Scalar(50,50,50),dst_add);
  imshow("added origin_src",dst_add);
  waitKey(0);
  //减法
  subtract(origin_src,Scalar(50,50,50),dst_subtract);
  imshow("subtracted origin_src",dst_subtract);
  waitKey(0);
  //乘法
  multiply(origin_src,Scalar(3,3,3),dst_multiply);
  imshow("divided origin_src",dst_multiply);
  waitKey(0);
  //除法
  divide(origin_src,Scalar(3,3,3),dst_divide);
  imshow("Multiplied origin_src",dst_divide);
  waitKey(0);
  return 0;
}
int g_r_n()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> dist(0,255);
  return dist(gen);
}
```
- Mat对象里的像素值可以通过加减同Size的Mat对象或同channels的Scalar对象进行运算
- openCV提供了一些内置函数：
  1. add(加数,加数,结果)
  2. subtract(被减数,减数,结果)
  3. multiply(乘数,乘数,结果)
  4. divide(被除数,除数,结果)
  **在进行上述操作时务必确保两个参与运算的矩阵是相同类型的**
- **注意**初始化Mat对象时，若用Size则为(width,height),若直接输入则先height后width
## ==06-矩形对象及其操作==
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
using namespace cv;
using namespace std;
void Rect_Picture_Show(Mat src1,Mat src2);
int main(int argc,char ** argv)
{
  Mat with_rctg_1(Size(400,400),CV_8UC3,Scalar(32,64,128));
  Mat with_rctg_2 = with_rctg_1.clone();
  Rect rctg_1(Point(50,50),Point(350,250));
  Rect rctg_2(Point(150,100),Point(250,350));
  rectangle(with_rctg_1,rctg_1,Scalar(255,255,0),-1,LINE_8,0);
  rectangle(with_rctg_2,rctg_2,Scalar(255,255,0),-1,LINE_8,0);
  imshow("Rectangle",with_rctg_1);
  waitKey(0);
  imshow("Rectangle",with_rctg_2);
  waitKey(0);
  imshow("Rectangle",with_rctg_2 & with_rctg_1);
  waitKey(0);
  Mat Or_ = with_rctg_2 | with_rctg_1;
  for( int i = 0 ; i<3 ; i++ )
    cout << static_cast<int>(Or_.at<Vec3b>(200,200)[i]) << endl;
  cout << "rctg_1面积：" << rctg_1.area() << endl;
  for( int i = 0 ; i<3 ; i++ )
    cout << static_cast<int>(Or_.at<Vec3b>(150,300)[i]) << endl;
  cout << "rctg_2面积：" << rctg_2.area() << endl;
  imshow("Rectangle",Or_);
  waitKey(0);
  imshow("Rectangle",with_rctg_2 ^ with_rctg_1);
  waitKey(0);
  imshow("Rectangle", ~ with_rctg_1);
  waitKey(0);

  //Rect_Picture_Show(imread("park.png"),imread("garden.png"));
  return 0;
}
void Rect_Picture_Show(Mat src1,Mat src2)
{
  cout << "src1: " << src1.cols << "x" << src1.rows 
       << "src2: " << src2.cols << "x" << src2.rows << endl;

  resize(src2, src2, src1.size());
  Mat result_And = src1&src2;
  imshow("AND Result",result_And);
  waitKey(0);
  Mat result_Or = src1|src2;
  imshow("OR Result",result_Or);
  waitKey(0);
  Mat result_Xor = src1^src2;
  imshow("XOR Result",result_Xor);
  waitKey(0);
  Mat result_Not = ~src2;
  imshow("Not Result",result_Not);
  waitKey(0);
  //imwrite("/home/line/ROSlearning_LJK/openCV/Xor_mix.png",result);
}
```
#### Rect
- Rect 是 OpenCV 中表示矩形区域的类，广泛用于 ROI 提取、绘图、目标检测等场景。
- Rect对象的生成
  1. Rect param_(x,y,width,height)
   注：(x,y指左上角坐标)
  2. Rect param_(Point(x<sub>1</sub>,y<sub>1</sub>),Point(x<sub>2</sub>,y<sub>2</sub>))
   注：(x<sub>1</sub>,y<sub>1</sub>)为左上角坐标，(x<sub>2</sub>,y<sub>2</sub>)为右下角坐标
  3. Rect param_(Point(x,y),Size(width,height))
   注：Point(x,y)为左上角坐标
- Rect对象的操作:
  1. rect.tl()获取左上角坐标
  2. rect.br()获取右下角坐标
  3. rect.aera()获取面积
  4. Mat sub = src(rect) 获取ROI
- rectangle函数
  用于将已知的矩形覆盖到图像中
  用法:rectangle(picture_src,rect_param,filled_color,Line_width,Style,float_shift)
  1. picture_src:图片源，也就是你想要用矩形覆盖的Mat对象
  2. rect_param:Rect矩形变量
  3. filled_color:填充颜色，用Scalar()进行声明
  4. Line_width:线宽，-1时为全填充
  5. Style:线条类型，默认Line_8
  6. float_shift:像素信息的小数位,默认0
## ==07==通道的分离
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
void DIY_channels_split(Mat&,int,int);
void split_merge_channels(Mat&,int,int);
void mix_channels(Mat&,int,int);

int main(int argc,char ** argv){
  Mat src_1 = imread("garden.png");
  int height = src_1.rows;
  int width = src_1.cols;
  //DIY_channels_split(src_1,height,width);
  //split_merge_channels(src_1,height,width);
  mix_channels(src_1,height,width);
  return 0;
}

void DIY_channels_split(Mat& src_1,int height,int width)
{
  Mat R_src,G_src,B_src;

  R_src = Mat::zeros(Size(width,height),CV_8UC3);
  R_src.copyTo(G_src);
  R_src.copyTo(B_src);
    int dims = R_src.channels();
  for (int h = 0; h<height ; h++)
    for (int w = 0; w<width ; w++)
    {
      if(dims == 3)
      {
        Vec3b pixel = src_1.at<Vec3b>(h,w);
        B_src.at<Vec3b>(h,w)[0] |= pixel[0];
        G_src.at<Vec3b>(h,w)[1] |= pixel[1];
        R_src.at<Vec3b>(h,w)[2] |= pixel[2];
      }
    }
  imshow("Blue",B_src);
  waitKey(0);
  imshow("Green",G_src);
  waitKey(0);
  imshow("Red",R_src);
  waitKey(0);
  imshow("All",R_src + B_src + G_src);
  waitKey(0);
  imshow("All",R_src + B_src + G_src);
  waitKey(0);
}
void split_merge_channels(Mat& src_1,int height,int width)
{
  std::vector<Mat> channels_hub;
  split(src_1,channels_hub);
  Mat zero_0 = Mat::zeros(height,width,CV_8UC1);
  
  Mat B_chn[3] = {channels_hub[0],zero_0,zero_0};
  Mat blue_img;
  merge(B_chn,3,blue_img);

  Mat G_chn[3] = {zero_0,channels_hub[1],zero_0};
  Mat green_img;
  merge(G_chn,3,green_img);

  Mat R_chn[3] = {zero_0,zero_0,channels_hub[2]};
  Mat red_img;
  merge(R_chn,3,red_img);

  imshow("Blue",blue_img);
  waitKey(0);
  imshow("Green",green_img);
  waitKey(0);
  imshow("Red",red_img);
  waitKey(0);
}
void mix_channels(Mat& src_1,int height,int width)
{
  std::string Name[]={"Red","Green","Blue"};
  Mat ZERO_ = Mat::zeros(Size(width,height),CV_8UC1);
  Mat Format_split[3] = {ZERO_,ZERO_,ZERO_};
  Mat bgr[3];
  Mat image;
  int color_format[] = {0,2,1,1,2,0};
  for(int i = 0;i < 3 ; i++ )
    bgr[i].create(Size(width,height),CV_8UC1);
  mixChannels(&src_1,1,bgr,3,color_format,3);
  for(int i = 0;i < 3 ; i++ ){
    Format_split[i]=bgr[i];
    merge(Format_split,3,image);
    imshow(Name[i],image);
    waitKey(0);
    for(int i = 0;i < 3 ; i++ )
      Format_split[i] = ZERO_;
  }
}
```
- split函数可以拆分BGR图像并将每个通道对应的矩阵传入到后面加入的Mat数组里
  语法:`split(image,vector)`
- merge函数可以将拆分的通道合并为图像
  语法:`merge(vector,channel_num,destination)`
- Mat数组里只有一个通道非0时显示的才是该非零通道的二值化颜色
- **注意：** 在使用多通道Mat时,at<>()的<>里绝不能填uchar,而是Vec3b,Vec4b,Vec3f这样的通道数组
```cpp
void cv::line(InputOutputArray img,
              Point pt1,                    // 起点
              Point pt2,                    // 终点
              const Scalar& color,          // 颜色
              int thickness = 1,            // 线宽
              int lineType = LINE_8,        // 线型
              int shift = 0);      
void cv::normalize(InputArray src,
                   InputOutputArray dst,
                   double alpha = 1,
                   double beta = 0,
                   int norm_type = NORM_L2,
                   int dtype = -1,
                   InputArray mask = noArray());    // 坐标小数位数
cv::resize(src, dst, Size(), 0.5, 0.5, INTER_AREA);   // 缩小一半
//                            ↑    ↑
//                            fx   fy（比例）
void cv::warpAffine(InputArray src,
                    OutputArray dst,
                    InputArray M,                          // 2×3 变换矩阵
                    Size dsize,                            // 输出尺寸
                    int flags = INTER_LINEAR,              // 插值方式
                    int borderMode = BORDER_CONSTANT,      // 边界填充
                    const Scalar& borderValue = Scalar()); // 填充颜色
void cv::filter2D(
    InputArray  src,          // 输入图像
    OutputArray dst,          // 输出图像
    int         ddepth,       // 输出深度，如 CV_32F、CV_8U、-1(同输入)
    InputArray  kernel,       // 卷积核（单通道浮点矩阵）
    Point       anchor = Point(-1,-1),   // 核锚点，默认中心
    double      delta = 0,    // 加到结果上的偏置
    int         borderType = BORDER_DEFAULT  // 边界处理
);              
```
## ==11==卷积
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <cmath>

using namespace cv;
using namespace std;

Mat mean = (Mat_<float>(3,3) <<
    1/9.0f,1/9.0f,1/9.0f,
    1/9.0f,1/9.0f,1/9.0f,
    1/9.0f,1/9.0f,1/9.0f);
Mat Gauss = (Mat_<float>(3,3) <<
    1/16.0f,2/16.0f,1/16.0f,
    2/16.0f,4/16.0f,2/16.0f,
    1/16.0f,2/16.0f,1/16.0f);
Mat Sobel_ = (Mat_<float>(3,3) <<
    -1, 0,  1,
    -2, 0,  2,
    -1, 0,  1);

Mat curl_kernel(Mat&,int,int);

int main(int argc,char ** argv)
{
  Mat image = imread("park_gray.png");
  cvtColor(image,image,COLOR_BGR2GRAY);
  cout << "type=" << image.type()
       << " channels=" << image.channels() << endl;
  int height = image.rows;
  int width = image.cols;
  cout <<width<<":"<<height<< endl;
  Mat Convoluted_result= curl_kernel(image,height,width);
  cout <<Convoluted_result.cols<<":"<<Convoluted_result.rows<< endl;
  imshow("Convoluted Result",Convoluted_result);
  waitKey(0);
  return 0;
}
Mat curl_kernel(Mat& image,int height,int width)
{
  Mat Convoluted_result = Mat::zeros(Size(width,height),CV_8UC1);
  cout << "image.rows=" << image.rows << " image.cols=" << image.cols << endl;
  cout << "height=" << height << " width=" << width << endl;
  Mat Convolution_kernel = Sobel_;

  for(int Y_ctr = 1;Y_ctr<height;Y_ctr++)
    for(int X_ctr = 1;X_ctr<width;X_ctr++){
    {
      float Temp = 0.0f;
      for(int delta_x = -1; delta_x < 2 ;delta_x++)
        for(int delta_y = -1; delta_y < 2;delta_y++)
        {
          Temp += Convolution_kernel.at<float>(1+delta_y,1+delta_x) * image.at<uchar>(Y_ctr+delta_y,X_ctr+delta_x);
        }
      Convoluted_result.at<uchar>(Y_ctr,X_ctr) = saturate_cast<uchar>(Temp);
    }
  }
  cout << "result.rows=" << Convoluted_result.rows
       << " result.cols=" << Convoluted_result.cols << endl;
  return Convoluted_result;
}
```
#### ==卷积函数==
- 均值滤波
```cpp
Mat dst;
blur(src, dst, Size(3,3));            // 3x3 均值
blur(src, dst, Size(5,5));            // 5x5 均值
```
- 高斯滤波
```cpp
Mat dst;
GaussianBlur(src, dst, Size(5,5), 0);   // sigma 由核大小自动算
GaussianBlur(src, dst, Size(0,0), 1.5); // 核大小由 sigma 自动算（推荐）
```
- 中值滤波
```cpp
Mat dst;
medianBlur(src, dst, 5);   // 5x5 邻域取中值，对椒盐噪声特别有效
```
- 双边滤波
```cpp
Mat dst;
bilateralFilter(src, dst, 9, 75, 75);
// 参数：邻域直径、颜色 sigma、空间 sigma
```
- Sobel梯度
```cpp
Mat gx, gy;
Sobel(src, gx, CV_32F, 1, 0, 3);   // x 方向一阶导
Sobel(src, gy, CV_32F, 0, 1, 3);   // y 方向一阶导
```
- 拉普拉斯
```cpp
Mat lap;
Laplacian(src, lap, CV_32F);
```
- 可分离卷积
```cpp
Mat kx = (Mat_<float>(1,3) << 1, 2, 1);
Mat ky = (Mat_<float>(3,1) << 1, 2, 1);
sepFilter2D(src, dst, CV_32F, kx, ky);
```