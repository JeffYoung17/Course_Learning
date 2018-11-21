// modified by jeff
//
// Created by xiang on 12/21/17.
//
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

#include "sophus/se3.h"

typedef vector<Vector3d, Eigen::aligned_allocator<Vector3d>> VecVector3d;
typedef vector<Vector2d, Eigen::aligned_allocator<Vector3d>> VecVector2d;
typedef Matrix<double, 6, 1> Vector6d;

string p3d_file = "../p3d.txt";
string p2d_file = "../p2d.txt";

int main(int argc, char **argv) {

    VecVector2d p2d;
    VecVector3d p3d;
    Matrix3d K;
    double fx = 520.9, fy = 521.0, cx = 325.1, cy = 249.7;
    K << fx, 0, cx, 0, fy, cy, 0, 0, 1;

    // load points in to p3d and p2d 
    // START YOUR CODE HERE
    // 匹配点在第二张图片的像素坐标
    string line;
    fstream fin_pixel(p2d_file);
    double u,v;
    while( getline(fin_pixel,line) )
    {
        stringstream lineStream(line);
        lineStream>>u>>v;
        Eigen::Vector2d pixel(u,v);
        p2d.push_back(pixel);
    }
    // load point of world coordinate
    // 一般情况下，第一张图片的相机坐标系作为第二张图片的参考系
    fstream fin_point(p3d_file);
    double Xc, Yc, Zc;
    while( getline(fin_point, line) ) {
        stringstream lineStream(line);
        lineStream>>Xc>>Yc>>Zc;
        Eigen::Vector3d point(Xc, Yc, Zc);
        p3d.push_back(point);
    }
    // END YOUR CODE HERE

    assert(p3d.size() == p2d.size());

    int iterations = 100;
    double cost = 0, lastCost = 0;
    int nPoints = p3d.size();
    cout << "points: " << nPoints << endl;

    Sophus::SE3 T_esti; // estimated pose

    for (int iter = 0; iter < iterations; iter++) {

        Matrix<double, 6, 6> H = Matrix<double, 6, 6>::Zero();
        Vector6d b = Vector6d::Zero();

        cost = 0;
        // compute cost
        for (int i = 0; i < nPoints; i++) {
            
            // compute cost for p3d[I] and p2d[I]
            // START YOUR CODE HERE 
            Vector2d e;
            Vector3d p_camera_coor;
            p_camera_coor = ( T_esti.matrix() * p3d[i].homogeneous() ).hnormalized(); // 3 dimension
            //cout << "camera coor of point: " << p_camera_coor.transpose() << endl;
            e = p2d[i] - ( (1/p3d[i][2]) * (K * p_camera_coor )).hnormalized();
	        // END YOUR CODE HERE

	        // compute jacobian
            Matrix<double, 2, 6> J;
            // START YOUR CODE HERE 
            J(0, 0) = -fx / p_camera_coor[2];
            J(0, 1) = 0;
            J(0, 2) = fx * p_camera_coor[0] / pow(p_camera_coor[2], 2);
            J(0, 3) = fx * p_camera_coor[0] * p_camera_coor[1] / pow(p_camera_coor[2], 2);
            J(0, 4) = -fx - fx * pow(p_camera_coor[0]/p_camera_coor[2], 2);
            J(0, 5) = fx * (p_camera_coor[1]/p_camera_coor[2]);
            J(1, 0) = 0;
            J(1, 1) = -fy / p_camera_coor[2];
            J(1, 2) = fy * p_camera_coor[1] / pow(p_camera_coor[2], 2);
            J(1, 3) = fy + fy * pow(p_camera_coor[1]/p_camera_coor[2], 2);
            J(1, 4) = fy * p_camera_coor[0] * p_camera_coor[1] / pow(p_camera_coor[2], 2);
            J(1, 5) = -fy * p_camera_coor[0] / p_camera_coor[2];
	        // END YOUR CODE HERE

            H += J.transpose() * J;
            b += -J.transpose() * e;
            
            // added by myself
            cost += e[0]*e[0] + e[1]*e[1];
        }

	    // solve dx 
        Vector6d dx;
        // START YOUR CODE HERE 
        dx = H.ldlt().solve(b);
        // END YOUR CODE HERE

        if (isnan(dx[0])) {
            cout << "result is nan!" << endl;
            break;
        }

        if (iter > 0 && cost >= lastCost) {
            // cost increase, update is not good
            cout << "cost: " << cost << ", last cost: " << lastCost << endl;
            break;
        }

        // update your estimation
        // START YOUR CODE HERE 
        T_esti = Sophus::SE3::exp(dx) * T_esti;
        // END YOUR CODE HERE
        
        lastCost = cost;

        cout << "iteration " << iter << " cost=" << cout.precision(12) << cost << endl;
    }

    cout << "estimated pose: \n" << T_esti.matrix() << endl;
    return 0;
}
