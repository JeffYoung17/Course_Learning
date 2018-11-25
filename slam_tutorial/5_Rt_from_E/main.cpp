#include <iostream>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace Eigen;

#include "sophus/so3.h"

int main ( int argc, char** argv )
{
    Matrix3d E;
    E << -0.0203618550523477, -0.4007110038118445, -0.03324074249824097,
            0.3939270778216369, -0.03506401846698079, 0.5857110303721015,
            -0.006788487241438284, -0.5815434272915686, -0.01438258684486258;

    // SVD decomposition
    Matrix3d R;
    Vector3d t;
    Matrix3d U, V, Sigma;
    JacobiSVD<MatrixXd> svd( E, ComputeThinU|ComputeThinV );
    U = svd.matrixU();
    V = svd.matrixV();
    Sigma = U.inverse() * E * ( V.transpose() ).inverse();

    // compute all R,t
    Matrix3d t1_hat;
    Matrix3d t2_hat;
    Matrix3d R1;
    Matrix3d R2;

    Matrix3d Rz_hfPI = AngleAxisd( M_PI/2, Eigen::Vector3d(0,0,1) ).toRotationMatrix();
    t1_hat = U * Rz_hfPI * Sigma * U.transpose();
    t2_hat = U * Rz_hfPI.inverse() * Sigma * U.transpose();
    R1 = U * Rz_hfPI.transpose() * V.transpose();
    R2 = U * (Rz_hfPI.inverse()).transpose() * V.transpose();

    // output
    cout << "R1 = " << R1 << endl;
    cout << "R2 = " << R2 << endl;
    cout << "t1 = " << Sophus::SO3::vee(t1_hat) << endl;
    cout << "t2 = " << Sophus::SO3::vee(t2_hat) << endl;

    Matrix3d tR = t1_hat * R1;
    cout << "t^R = " << tR << endl;

    return 0;
}