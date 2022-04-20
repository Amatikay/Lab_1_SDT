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
    std::string patronymic;
public:
    Person(){

    }
    Person(const std::string full_name); // получает строку, создает обьект
    Person(const Person& person){ //конструктор копирования
        last_name = person.last_name;
        first_name = person.first_name;
        patronymic = person.patronymic;
    }
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; }
    const std::string& getPatronymic() const { return patronymic; }
    void setLastName(const std::string &last);
    void setFirstname(const std::string &first);
    void setPatronymic(const std::string &patronymic);
};


#endif //LAB_23__1_SOFTWARE__PERSON_H
