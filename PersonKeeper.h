//
// Created by sergey on 15.03.2022.
//

#ifndef LAB_23__1_SOFTWARE__PERSONKEEPER_H
#define LAB_23__1_SOFTWARE__PERSONKEEPER_H
#include "Person.h"
#include "Stack.h"

class PersonKeeper {

private:
    PersonKeeper(){
        //Stack<Person> PersonStack; паттерн одиночка по этому конструктор не создается
    }
    PersonKeeper(const PersonKeeper&);// для патрена одиночка не реализую
    PersonKeeper& operator= (PersonKeeper const&);// для патрена одиночка не реализую
    ~PersonKeeper(){}
    Stack<Person> PersonStack;

public:
    Stack<Person> readPersons( std::string file_path);
    void writePersons(std::string file_path);
    static PersonKeeper& Instance(){ //статический создающий метод
        //создание обьекта при первом вызове метода
        static PersonKeeper s;
        return s;
    }


};


#endif //LAB_23__1_SOFTWARE__PERSONKEEPER_H
