//
// Created by sergey on 15.03.2022.
//

#ifndef LAB_23__1_SOFTWARE__PERSON_H
#define LAB_23__1_SOFTWARE__PERSON_H


#include <string>

class Person
{
private:
    long key;
    std::string last_name;
    std::string first_name;
public:
    Person();
    Person(const std::string full_name);
    Person(const Person&);
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; }
    void setLastName(const std::string&);
    void setFirstname(const std::string&);
};


#endif //LAB_23__1_SOFTWARE__PERSON_H
