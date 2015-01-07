
#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>

#include "fzhDefines.hpp"
#include "facedetect.hpp"

namespace fzhcore
{
    const std::string FaceRecogniser::cascadeName_ = fzhcore::HARR_MODEL;
    const std::string FaceRecogniser::nestedCascadeName_ = fzhcore::HARR_NESTED_MODEL;
    const size_t FaceRecogniser::maxCaptured_ = 20;

    FaceRecogniser::FaceRecogniser()
        :numCaptured_(0)
    {

    }

    FaceRecogniser::~FaceRecogniser()
    {
        numCaptured_ = 0;
    }

    bool FaceRecogniser::isFinished() 
    {
        bool isFinished = (numCaptured_ >= maxCaptured_);

        if ( isFinished)
        {
            numCaptured_ = 0;
        }      
        
        return isFinished;
    }

    bool FaceRecogniser::detectAndDraw(cv::Mat& img)
    {
        cv::Mat frame, frameCopy, image;
        const std::string scaleOpt = "--scale=";
        size_t scaleOptLen = scaleOpt.length();
        const std::string cascadeOpt = "--cascade=";
        size_t cascadeOptLen = cascadeOpt.length();
        const std::string nestedCascadeOpt = "--nested-cascade";
        size_t nestedCascadeOptLen = nestedCascadeOpt.length();
        const std::string tryFlipOpt = "--try-flip";
        size_t tryFlipOptLen = tryFlipOpt.length();
        std::string inputName;
        bool tryflip = false;

        cv::CascadeClassifier cascade, nestedCascade;
        double scale = 1;

        if (!cascade.load(cascadeName_))
        {
            std::cerr << "ERROR: Could not load classifier cascade" << std::endl;

            return false;
        }
        
        return detectAndDraw_(img, cascade, nestedCascade, scale, tryflip);
    }

    bool FaceRecogniser::detectAndDraw_(cv::Mat& img, cv::CascadeClassifier& cascade,
        cv::CascadeClassifier& nestedCascade,
        double scale, bool tryflip)
    {
        int i = 0;
        double t = 0;
        std::vector<cv::Rect> faces, faces2;
        const static cv::Scalar colors[] = { CV_RGB(0, 0, 255),
            CV_RGB(0, 128, 255),
            CV_RGB(0, 255, 255),
            CV_RGB(0, 255, 0),
            CV_RGB(255, 128, 0),
            CV_RGB(255, 255, 0),
            CV_RGB(255, 0, 0),
            CV_RGB(255, 0, 255) };
        cv::Mat gray, smallImg(cvRound(img.rows / scale), cvRound(img.cols / scale), CV_8UC1);

        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        cv::resize(gray, smallImg, smallImg.size(), 0, 0, cv::INTER_LINEAR);
        cv::equalizeHist(smallImg, smallImg);

        t = (double)cvGetTickCount();
        cascade.detectMultiScale(smallImg, faces,
            1.1, 2, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            | cv::CASCADE_SCALE_IMAGE
            ,
            cv::Size(30, 30));
       
        t = (double)cvGetTickCount() - t;
        printf("detection time = %g ms\n", t / ((double)cvGetTickFrequency()*1000.));
        for (std::vector<cv::Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++)
        {
            cv::Mat smallImgROI;
            std::vector<cv::Rect> nestedObjects;
            cv::Point center;
            cv::Scalar color = colors[i % 8];
            int radius;

            double aspect_ratio = (double)r->width / r->height;
            if (0.75 < aspect_ratio && aspect_ratio < 1.3)
            {
                center.x = cvRound((r->x + r->width*0.5)*scale);
                center.y = cvRound((r->y + r->height*0.5)*scale);
                radius = cvRound((r->width + r->height)*0.25*scale);
                circle(img, center, radius, color, 3, 8, 0);
            }
            else
                rectangle(img, cvPoint(cvRound(r->x*scale), cvRound(r->y*scale)),
                cvPoint(cvRound((r->x + r->width - 1)*scale), cvRound((r->y + r->height - 1)*scale)),
                color, 3, 8, 0);
            if (nestedCascade.empty())
                continue;
            smallImgROI = smallImg(*r);
            nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
                1.1, 2, 0
                //|CASCADE_FIND_BIGGEST_OBJECT
                //|CASCADE_DO_ROUGH_SEARCH
                //|CASCADE_DO_CANNY_PRUNING
                | cv::CASCADE_SCALE_IMAGE
                ,
                cv::Size(30, 30));
            for (std::vector<cv::Rect>::const_iterator nr = nestedObjects.begin(); nr != nestedObjects.end(); nr++)
            {
                center.x = cvRound((r->x + nr->x + nr->width*0.5)*scale);
                center.y = cvRound((r->y + nr->y + nr->height*0.5)*scale);
                radius = cvRound((nr->width + nr->height)*0.25*scale);
                cv::circle(img, center, radius, color, 3, 8, 0);
            }
        }

        bool foundFace = !faces.empty();
        if (foundFace)
        {
            ++numCaptured_;
        }

        return foundFace;
    }

    int FaceRecogniser::getNumCapture() const
    {
        return numCaptured_;
    }

}