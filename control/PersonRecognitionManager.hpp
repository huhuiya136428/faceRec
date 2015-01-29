#pragma once

#include <opencv2/core/core.hpp>

#include "../core/algorithm/facedetect.hpp"

#define MAX_CAPTURE 20

namespace fzhcore
{  

    class PersonRecognitionManager
    {
        
    public:
        PersonRecognitionManager();
        virtual ~PersonRecognitionManager();

        bool detectFace(cv::Mat mat);
        bool isCollectionFinished();
        void train();
        int getNumCapture();
    private:

        fzhcore::FaceRecogniser faceRecogniser_;

    };
}



