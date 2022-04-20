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
        Stack<Person> PersonStack;
    }
    PersonKeeper(const PersonKeeper&);
    PersonKeeper& operator= (PersonKeeper const&);
    ~PersonKeeper(){}
    Stack<Person> PersonStack;

public:
    Stack<Person> readPersons( std::string file_path);
    void writePersons(std::string file_path);
    /*
     * TODO
     *  Расписать в коментариях зачем нужна Instanse()
     */
    static PersonKeeper& Instance(){
        static PersonKeeper s;
        return s;
    }


};


#endif //LAB_23__1_SOFTWARE__PERSONKEEPER_H
