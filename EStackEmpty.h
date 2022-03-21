//
// Created by sergey on 12.03.2022.
//

#ifndef STACKLIB_ESTACKEMPTY_H
#define STACKLIB_ESTACKEMPTY_H


#include "EStackException.h"

class EStackEmpty : public EStackException
{
public:
    EStackEmpty() : EStackException()
    {
        std::cerr <<"A stack is empty." << std::endl;

    }
};

#endif //STACKLIB_ESTACKEMPTY_H
