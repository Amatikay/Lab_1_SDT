//
// Created by sergey on 15.03.2022.
//

#ifndef LAB_23__1_SOFTWARE__PERSONKEEPER_H
#define LAB_23__1_SOFTWARE__PERSONKEEPER_H
#include "Person.h"
#include "Stack.h"

class PersonKeeper {
public:
    PersonKeeper();
    PersonKeeper(const PersonKeeper&);
    ~PersonKeeper();
    void readPersons();
    void writePersons();
};


#endif //LAB_23__1_SOFTWARE__PERSONKEEPER_H
