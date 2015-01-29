#include "PersonRecognitionManager.hpp"



namespace fzhcore
{


PersonRecognitionManager::PersonRecognitionManager()
{

}

PersonRecognitionManager::~PersonRecognitionManager()
{

}

bool PersonRecognitionManager::detectFace(cv::Mat mat)
{
    return faceRecogniser_.detectAndDraw(mat);
}

bool PersonRecognitionManager::isCollectionFinished()
{
    return faceRecogniser_.isCollectionFinished();
}

void PersonRecognitionManager::train()
{
    faceRecogniser_.train();
}

int PersonRecognitionManager::getNumCapture()
{
    return faceRecogniser_.getNumCapture();
}
}
