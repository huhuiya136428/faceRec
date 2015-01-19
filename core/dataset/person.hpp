#include "opencv2/core/utility.hpp"


#include <string>


namespace fzhcore
{
    class DataSet
    {
    public:
        DataSet();
        virtual ~DataSet();

        virtual bool getData() = 0;
        virtual bool setData() = 0;        


    };

    class Person: public DataSet
    {
    public:
        Person();
        virtual ~Person();
                
    
    private:
        
    private:
        std::string name_;
        std::int label_;

       
    };
   
}
