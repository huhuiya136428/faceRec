#include "person.hpp"



namespace fzhcore
{


    DataSet::DataSet()
    {

    }

    DataSet::~DataSet()
    {

    }

    Person::Person()
        : label_(-1)
    {

    }

    Person::Person(std::string name, int label)
        : name_(name), label_(label)
    {

    }

    Person::~Person()
    {

    }



    void PersonList::addPerson(std::string name, int label)
    {
        persons_[label] = Person(name, label);
    }

    void PersonList::removePerson(int label)
    {
        persons_.erase(label);
    }

    Person PersonList::getPerson(int label)
    {
        return persons_[label];
    }

    PersonList::PersonList()
    {

    }

    PersonList::~PersonList()
    {

    }

}