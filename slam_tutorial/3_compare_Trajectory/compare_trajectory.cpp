#include <sophus/se3.h>
#include <string>
#include <iostream>
#include <fstream>

// need pangolin for plotting trajectory

#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

// path to trajectory file
string estimate_filepath = "../estimated.txt";
string groundtruth_filepath = "../groundtruth.txt";

// function for plotting trajectory, don't edit this code
// start point is red and end point is blue

void DrawTrajectory(vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses,
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_another );

double compute_RMSE(vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses,
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_another );


int main(int argc, char **argv) {

    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_estimate;
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_groundtruth;
    
    /// implement pose reading code
    // start your code here (5~10 lines)
    
    string single_line; 
    double t, tx, ty, tz, qx, qy, qz, qw;
    
    fstream file1(estimate_filepath);
    while( getline(file1, single_line) )
    {
        stringstream in_stream(single_line);
        in_stream >> t >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
        Eigen::Vector3d t( tx, ty, tz );
        Eigen::Quaterniond q = Eigen::Quaterniond( qx, qy, qz, qw ).normalized();
        Sophus::SE3 SE3_qt( q, t );
        poses_estimate.push_back(SE3_qt);
    }

    fstream file2(groundtruth_filepath);
    while( getline( file2, single_line ))
    {
        stringstream in_stream(single_line);
        in_stream >> t >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
        Eigen::Vector3d t( tx, ty, tz );
        Eigen::Quaterniond q = Eigen::Quaterniond( qx, qy, qz, qw ).normalized();
        Sophus::SE3 SE3_qt( q, t );
        poses_groundtruth.push_back(SE3_qt);
    }

    // end your code here

    cout << "RMSE is : " << compute_RMSE( poses_groundtruth , poses_estimate ) << endl;
    
    // draw trajectory in pangolin
    DrawTrajectory( poses_estimate, poses_groundtruth );
    return 0;

}

/*******************************************************************************************/
void DrawTrajectory(vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses,
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_another) 
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
            
            glColor3f(1 - (float) i / poses_another.size(), 0.0f, (float) i / poses_another.size());
            glBegin(GL_LINES);
            auto p1_g = poses_another[i], p2_g = poses_another[i + 1];
            glVertex3d(p1_g.translation()[0], p1_g.translation()[1], p1_g.translation()[2]);
            glVertex3d(p2_g.translation()[0], p2_g.translation()[1], p2_g.translation()[2]);            
            
            glEnd();
        }

        pangolin::FinishFrame();
        usleep(5000);   // sleep 5 ms
    }

}

double compute_RMSE(vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses ,
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_another)
{
    vector<double> error;
    Eigen::Matrix<double,6,1> se3_error;
    for ( int i=0; i<poses.size()-1; i++)
    {
        se3_error = Sophus::SE3::log( poses[i].inverse() * poses_another[i] );
        error.push_back( se3_error.squaredNorm() );

    }

    double RMSE = 0.0;
    for( int i=0; i<error.size(); i++ )
    {
        RMSE += error[i];
    }

    RMSE = RMSE/error.size();
    RMSE = sqrt(RMSE);
    return RMSE; 
}