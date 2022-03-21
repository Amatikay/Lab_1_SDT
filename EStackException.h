//
// Created by sergey on 12.03.2022.
//

#ifndef STACKLIB_ESTACKEXCEPTION_H
#define STACKLIB_ESTACKEXCEPTION_H


#include <iostream>
#include <cstring>

class EStackException
{
private:
    char* message;
public:
    EStackException()
    {

    }
    ~EStackException()
    {
        delete message;
    }

    const char* what() const
    {
        return message;
    }


};

#endif //STACKLIB_ESTACKEXCEPTION_H
