#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <pangolin/pangolin.h>
#include <unistd.h>

using namespace std;
using namespace Eigen;

string left_file = "../left.png";
string right_file = "../right.png";
string disparity_file = "../disparity.png";

void showPointCloud ( const vector< Vector4d, Eigen::aligned_allocator<Vector4d> > &pointcloud );


int main ( int argc, char** argv )
{
    double fx = 718.856, fy = 718.856, cx = 607.1928, cy = 185.2157;
    double b = 0.573;

    // read image as gray
    cv::Mat left = cv::imread( left_file, 0 );
    cv::Mat right = cv::imread( right_file, 0 );
    cv::Mat disparity = cv::imread( disparity_file, 0 );

    if( left.empty() || right.empty() || disparity.empty() )
    {
        cout << " image read error! " << endl;
        return -1;
    }

    vector< Vector4d, Eigen::aligned_allocator<Vector4d> > pointcloud;

    double f = fx;
    for ( int v = 0; v < left.rows; v+=2 )
        for ( int u = 0; u < left.cols; u+=2 )
    {
        Vector4d point(0, 0, 0, left.at<uchar>(v, u) / 255 );
        point[2] = f*b/disparity.at<uchar>(v, u); 
        point[0] = (u-cx)*point[2]/fx;
        point[1] = (v-cy)*point[2]/fy;
        //point[3] = left.at<uchar>(v,u);
        pointcloud.push_back(point);
    }

    showPointCloud(pointcloud);

    return 0;
}

void showPointCloud(const vector<Vector4d, Eigen::aligned_allocator<Vector4d>> &pointcloud) {

    if (pointcloud.empty()) {
        cerr << "Point cloud is empty!" << endl;
        return;
    }

    pangolin::CreateWindowAndBind("Point Cloud Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::OpenGlRenderState s_cam(
            pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
            pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
    );

    pangolin::View &d_cam = pangolin::CreateDisplay()
            .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
            .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        d_cam.Activate(s_cam);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glPointSize(2);
        glBegin(GL_POINTS);
        for (auto &p: pointcloud) {
            glColor3f(p[3], p[3], p[3]);
            glVertex3d(p[0], p[1], p[2]);
        }
        glEnd();
        pangolin::FinishFrame();
        usleep(5000);   // sleep 5 ms
    }
    return;
}