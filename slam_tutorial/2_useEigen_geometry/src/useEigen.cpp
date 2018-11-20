#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main( int argc, char** argv )
{
    // 设置
    Quaterniond q1( 0.55, 0.3, 0.2, 0.2);
    Quaterniond q2( -0.1, 0.3, -0.7, 0.2);
    Vector3d t1, t2;
    t1 << 0.7, 1.1, 0.2;
    t2 << -0.1, 0.4, 0.8;

    // 对四元数进行归一化
    q1 = q1.normalized();
    q2 = q2.normalized();

    // 从四元数转换成对应的旋转矩阵
    Matrix3d q1_rot_mat = Matrix3d::Identity();
    Matrix3d q2_rot_mat = Matrix3d::Identity();
    q1_rot_mat = q1.toRotationMatrix();
    q2_rot_mat = q2.toRotationMatrix();

    // 将旋转矩阵和平移向量组成变换矩阵
    Isometry3d Tc1w = Isometry3d::Identity();
    Tc1w.rotate( q1_rot_mat );
    Tc1w.pretranslate( t1 );

    Isometry3d Tc2w = Isometry3d::Identity();
    Tc2w.rotate( q2_rot_mat );
    Tc2w.pretranslate( t2 );

    Vector3d pw, pc1, pc2;
    pc1 << 0.5, -0.1, 0.2;
    pw = Tc1w.inverse() * pc1;

    cout << " coordinate of point in world frame is " << endl;
    cout << pw << endl;
    pc2 = Tc2w * pw;
    cout << " coordinate of point in robot2 frame is " << endl;
    cout << pc2 << endl;

    return 0;
}