#pragma once


#include "opencv2/core/utility.hpp"


#include <string>
#include <map>

namespace fzhcore
{
    class DataSet
    {
    public:
        DataSet();
        virtual ~DataSet();

      


    };

    class Person: public DataSet
    {
    public:
        Person();
        Person(std::string name, int label);
        virtual ~Person();
                
        
    private:
        std::string name_;
        int label_;       
    };

    class PersonList : public DataSet
    {
    public:
        PersonList();
        virtual ~PersonList();

        void addPerson(std::string name, int label);
        void removePerson(int label);        
        Person getPerson(int label);
       
    private:
        std::map<int, Person> persons_;

    };
}
