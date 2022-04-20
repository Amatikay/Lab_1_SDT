//
// Created by sergey on 20.04.2022.
//

#include <string.h>
#include<iostream>

namespace exceptions{
    class Exception{
    private:
        char* message;
    public:
        Exception(const char* arg_message)
        {
            message = new char[strlen(arg_message)+1];

            strcpy(message,arg_message);
        }

        Exception(const Exception& arg)
        {
            message = new char[strlen(arg.message)+1];

            strcpy(message,arg.message);
        }

        ~Exception()
        {
            delete message;
        }

        const char* what() const{ return message; }
    };
    class ExceptionData: public Exception{//обработка исключений связанными с некорректными данными
    public:
        explicit ExceptionData(const char* arg) : Exception(arg){
            std::cerr << what()<< std::endl;
        }

    };
    class ExceptionFile: public Exception{//обработка исключений связанных с файлами ( не открытия файла)
    public:
        explicit ExceptionFile(const char* arg) : Exception(arg){
            std::cerr << what()<< std::endl;
        }

    };
}


#ifndef LAB_23__1_SOFTWARE__EXCEPTION_H
#define LAB_23__1_SOFTWARE__EXCEPTION_H

#endif //LAB_23__1_SOFTWARE__EXCEPTION_H
