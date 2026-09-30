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
#define USING_VIDEO false
#define USING_HOUGH true

std::vector<Mat> edge_extract(Mat&,int,int);
int edge_find();
int GRN(int,int);
Mat Find_ConvexHull(Mat&,int,int,const std::vector<Point2f>&);
double line_pt_dist(double,double,Point);
// int video_cap(VideoCapture&,Mat&);