#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/core/utility.hpp"

#include "opencv2/videoio/videoio_c.h"

#include <string>


namespace fzhcore
{
    class IFaceRegister
    {
    public:
        virtual bool isFinished() = 0;

        virtual bool detectAndDraw(cv::Mat& img) = 0;

        virtual int getNumCapture() const = 0;
    };

    class FaceRecogniser: public IFaceRegister
    {
    public:
        FaceRecogniser();
        virtual ~FaceRecogniser();
                
        virtual bool isFinished();

        virtual bool detectAndDraw(cv::Mat& img);

        virtual int getNumCapture() const;
        const static size_t maxCaptured_;
    private:
        bool detectAndDraw_(cv::Mat& img, cv::CascadeClassifier& cascade,
            cv::CascadeClassifier& nestedCascade,
            double scale, bool tryflip);
        
    private:
        int numCaptured_;

        const static std::string cascadeName_;
        const static std::string nestedCascadeName_;

       
    };
   
}
