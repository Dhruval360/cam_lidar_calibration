#include "cam_lidar_calibration/feature_extractor.h"

#include <actionlib/server/simple_action_server.h>
#include <actionlib/client/simple_action_client.h>
#include <cam_lidar_calibration/RunOptimiseAction.h>

using actionlib::SimpleActionServer;
using cam_lidar_calibration::FeatureExtractor;

#if defined(__x86_64__)
    #include "matlab_checkerboard_detection/x86_64/matlabCheckerBoardDetect.h"
    #include "matlab_checkerboard_detection/x86_64/matlabCheckerBoardDetect_internal_types.h"
#elif defined(__aarch64__)
    #include "matlab_checkerboard_detection/aarch64/matlabCheckerBoardDetect.h"
    #include "matlab_checkerboard_detection/aarch64/matlabCheckerBoardDetect_internal_types.h"
#else
    #error "Unsupported CPU type"
#endif

int main(int argc, char** argv)
{
    #if defined(__x86_64__)
        static rtRunTimeErrorInfo s_emlrtRTEI{
            1,                         // lineNo
            "matlabCheckerBoardDetect" // fName
        };
    #elif defined(__aarch64__)
        static rtRunTimeErrorInfo s_emlrtRTEI{
            1,                            // lineNo
            1,                            // colNo
            "matlabCheckerBoardDetect"    // fName
            "feature_extraction_node.cpp" // pName
        };
    #else
        #error "Unsupported CPU type"
    #endif
    
    // Initialize Node and handles
    ros::init(argc, argv, "FeatureExtractor");
    ros::NodeHandle n;


    FeatureExtractor feature_extractor;
    SimpleActionServer<cam_lidar_calibration::RunOptimiseAction> optimise_action(
            n, "run_optimise", boost::bind(&FeatureExtractor::optimise, feature_extractor, _1, &optimise_action), false);
    optimise_action.start();

    ros::Rate loop_rate(10);

    ros::AsyncSpinner spinner(4);
    spinner.start();

    while (ros::ok())
    {
        if (feature_extractor.import_samples) 
        {
            actionlib::SimpleActionClient<cam_lidar_calibration::RunOptimiseAction> action_client("run_optimise", true);
            action_client.waitForServer();
            cam_lidar_calibration::RunOptimiseGoal goal;
            action_client.sendGoal(goal);
            break;
        }

        feature_extractor.visualiseSamples();
        loop_rate.sleep();
    }
    matlabCheckerBoardDetect_terminate();
    return 0;
}

