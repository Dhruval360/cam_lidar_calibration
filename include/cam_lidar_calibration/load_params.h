#ifndef load_params_h_
#define load_params_h_

#include <ros/ros.h>

#include <opencv2/core/mat.hpp>

namespace cam_lidar_calibration
{
struct initial_parameters_t
{
  std::string camera_topic;
  std::string lidar_topic;
  bool fisheye_model;
  int lidar_ring_count;
  cv::Size chessboard_pattern_size;
  int square_length;                 // in millimetres
  cv::Size board_dimensions;         // in millimetres
  cv::Point3f cb_translation_error;  // in millimetres
  cv::Mat cameramat;
  int distcoeff_num;
  cv::Mat distcoeff;
  std::pair<int, int> image_size;  // in pixels
};

void loadParams(const ros::NodeHandle& n, initial_parameters_t& i_params);

}  // namespace cam_lidar_calibration

#endif
