/*
 * Sophus的演示例程
**/
#include <iostream>
#include <cmath>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include "sophus/so3.h"
#include "sophus/se3.h"

using namespace std;
using namespace Eigen;

typedef Eigen::Matrix<double,6,1> Vector6d;

int main( int argc, char** argv )
{
    // SO(3) 和 so(3) 的构造和运算
    Eigen::Matrix3d R = Eigen::AngleAxisd( M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();

    Sophus::SO3 SO3_R( R );
    Sophus::SO3 SO3_v( 0, 0, M_PI/2 );
    Eigen::Quaterniond q( R );
    Sophus::SO3 SO3_q( q );

    cout << "SO(3) from R:\n" << SO3_R << endl;
    cout << "SO(3) from v:\n" << SO3_v << endl;
    cout << "SO(3) from q:\n" << SO3_q << endl;

    Eigen::Vector3d so3 = SO3_R.log();
    cout << "so(3) =\n" << so3.transpose() << endl;
    cout << "so(3) hat =\n" << Sophus::SO3::hat(so3) << endl;
    cout << "so(3) hat vee\n" << Sophus::SO3::vee( Sophus::SO3::hat(so3) ) << endl;

    // 增量扰动模型的更新
    Eigen::Vector3d update_so3(1e-4, 0, 0);
    Sophus::SO3 SO3_updated = Sophus::SO3::exp(update_so3) * SO3_R;
    cout << "SO(3) updated =\n" << SO3_updated << endl;

    cout << "ojbk, i'm a genius" << endl;
    cout << "now, let's deal with SE(3) and se(3)" << endl;

    Eigen::Vector3d t(1,0,0);
    Sophus::SE3 SE3_Rt(R, t);
    Sophus::SE3 SE3_qt(q, t);
    cout << "SE(3) from R,t =\n" << SE3_Rt << endl;
    cout << "SE(3) from q,t =\n" << SE3_qt << endl;

    Vector6d se3 = SE3_Rt.log();
    cout << "se(3) =\n" << se3.transpose() << endl;
    cout << "se(3) hat=\n" << Sophus::SE3::hat(se3) << endl;
    cout << "se(3) hat vee=\n" << Sophus::SE3::vee( Sophus::SE3::hat(se3) ) << endl;

    Vector6d update_se3;
    update_se3.setZero();
    update_se3(0,0) = 1e-4d;
    Sophus::SE3 SE3_updated = Sophus::SE3::exp(update_se3) * SE3_Rt;
    cout << "SE3 updated =\n" << SE3_updated.matrix() << endl;

    return 0;
}