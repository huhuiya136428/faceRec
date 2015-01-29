#pragma once


#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/core/utility.hpp"

#include "opencv2/videoio/videoio_c.h"

#include "opencv2/face.hpp"

#include <string>


namespace fzhcore
{
    class IFaceRegister
    {
    public:
        virtual bool isCollectionFinished() = 0;

        virtual bool detectAndDraw(cv::Mat& img) = 0;

        virtual int getNumCapture() const = 0;

        virtual void addSample(cv::Mat& image, int label) = 0;

        virtual void train() = 0;
    };

    class FaceRecogniser: public IFaceRegister
    {
    public:
        FaceRecogniser();
        virtual ~FaceRecogniser();
                
        virtual bool isCollectionFinished();

        virtual bool detectAndDraw(cv::Mat& img);

        virtual int getNumCapture() const;
        const static size_t maxCaptured_;

        virtual void addSample(cv::Mat& image, int label);

        virtual void train();
    private:
        bool detectAndDraw_(cv::Mat& img, cv::CascadeClassifier& cascade,
            cv::CascadeClassifier& nestedCascade,
            double scale, bool tryflip);
       
      
    private:
        int numCaptured_;

        const static std::string cascadeName_;
        const static std::string nestedCascadeName_;

        cv::Ptr<cv::face::FaceRecognizer> model_;

        std::vector<cv::Mat> images_;
        std::vector<int> labels_;
    };
   
}
