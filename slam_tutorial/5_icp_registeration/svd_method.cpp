#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include <sophus/se3.h>

#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

#include <pangolin/pangolin.h>

typedef vector<Vector3d, Eigen::aligned_allocator<Vector3d>> VecVector3d;
typedef vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> VecPose;
typedef Matrix<double, 6, 1> Vector6d;

void DrawTrajectory( VecPose poses, VecPose poses_real );

int main ( int argc, char** argv )
{
    // load estimated data and groundtruth
    VecPose pose_est, pose_gt;
    string one_line;
    double time_e, tx_e, ty_e, tz_e, qx_e, qy_e, qz_e, qw_e;
    double time_g, tx_g, ty_g, tz_g, qx_g, qy_g, qz_g, qw_g;
    // only have translation used as point
    VecVector3d p3d_est, p3d_gt;

    fstream file_obj( "../compare.txt" );
    if ( !file_obj ) {
        cerr << "no data loading." << endl;
        return -1;
    }
    while ( getline(file_obj, one_line) ) {
        stringstream s_in(one_line);
        s_in >> time_e >> tx_e >> ty_e >> tz_e >> qx_e >> qy_e >> qz_e >> qw_e
             >> time_g >> tx_g >> ty_g >> tz_g >> qx_g >> qy_g >> qz_g >> qw_g;
        Vector3d t_est( tx_e, ty_e, tz_e );
        Eigen::Quaterniond q_est = Eigen::Quaterniond( qx_e, qy_e, qz_e, qw_e );
        Sophus::SE3 qt_est(q_est, t_est);
        pose_est.push_back( qt_est );
        p3d_est.push_back( t_est );
        Vector3d t_gt( tx_g, ty_g, tz_g );
        Eigen::Quaterniond q_gt = Eigen::Quaterniond( qx_g, qy_g, qz_g, qw_g );
        Sophus::SE3 qt_gt( q_gt, t_gt );
        pose_gt.push_back( qt_gt );
        p3d_gt.push_back( t_gt );
    }
    cout << "data load done." << endl;
    // draw not matched pose
    // DrawTrajectory( pose_est, pose_gt );
    
    // icp registeration
    
    Vector3d p_est_centroid, p_gt_centroid;
    for ( auto& elem : p3d_est ) {
        p_est_centroid += elem;
    }

    for ( auto& elem : p3d_gt ) {
        p_gt_centroid += elem;
    }
    p_est_centroid = p_est_centroid / p3d_est.size();
    p_gt_centroid = p_gt_centroid / p3d_gt.size();
    cout << "centroid of p_est, p_gt are: " << p_est_centroid.transpose();
    cout << " " << p_gt_centroid.transpose() << endl;

    assert (p3d_est.size() == p3d_gt.size() );
    cout << "point's size: " << p3d_est.size() << endl;

    VecVector3d q3d_est, q3d_gt;
    for ( auto& elem : p3d_est ) {
        q3d_est.push_back( elem - p_est_centroid );
    }
    for ( auto& elem : p3d_gt ) {
        q3d_gt.push_back( elem - p_gt_centroid );
    }

    Matrix3d W = Matrix3d::Zero();
    for( int i=0; i<q3d_est.size(); i++ ) {
        W += q3d_gt[i] * ( q3d_est[i].transpose() );
    }
    Matrix3d U, V, R;
    JacobiSVD<MatrixXd> svd( W, ComputeThinU|ComputeThinV );
    U = svd.matrixU();
    V = svd.matrixV();
    R = U * V.transpose();
    Vector3d t;
    t = p_gt_centroid - R*p_est_centroid;
    Sophus::SE3 T_ge( R, t );


    cout << "estimated pose from est_coord -> groundtruth_coord: \n" << T_ge.matrix() << endl;

    // draw matched pose
    VecPose poses_matched;
    for ( auto& elem : pose_est ) {
        poses_matched.push_back( T_ge * elem );
    }

    assert( poses_matched.size() == pose_gt.size() );
    DrawTrajectory( poses_matched, pose_gt );

    return 0;
}

void DrawTrajectory( VecPose poses, VecPose poses_real )
{
    if (poses.empty()) {
        cerr << "Trajectory is empty!" << endl;
        return;
    }

    // create pangolin window and plot the trajectory
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
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

        glLineWidth(2);
        for (size_t i = 0; i < poses.size() - 1; i++) {
            
            glColor3f(1 - (float) i / poses.size(), 0.0f, (float) i / poses.size());
            glBegin(GL_LINES);
            auto p1 = poses[i], p2 = poses[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
            
            glColor3f(1 - (float) i / poses_real.size(), 0.0f, (float) i / poses_real.size());
            glBegin(GL_LINES);
            auto p1_g = poses_real[i], p2_g = poses_real[i + 1];
            glVertex3d(p1_g.translation()[0], p1_g.translation()[1], p1_g.translation()[2]);
            glVertex3d(p2_g.translation()[0], p2_g.translation()[1], p2_g.translation()[2]);            
            
            glEnd();
        }

        pangolin::FinishFrame();
        usleep(5000);   // sleep 5 ms
    }

}