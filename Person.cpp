//
// Created by sergey on 22.03.2022.
//
#include <string>
#include "Person.h"
#include "Exception.h"
#include <iostream>
#include <vector>
#include <sstream>
Person::Person(const std::string full_name) {


        /*
         * Я эти случаи уже проверил в PersonKeeper.cpp
         * но на всякий случаи прописал тут тоже
         */
        if(full_name==""){
            throw exceptions::ExceptionData("ФИО пустое");
        }
        if ((count(full_name.begin(), full_name.end(), ' '))!=2){
        throw exceptions::ExceptionData("В ФИО не 3 слова");
        }
        /*
         * Строку переданную в качетве аргумента преобразую
         * в вектор для разбиения по словам
         */
        std::vector<std::string> full_name_vector;
        std::istringstream ss(full_name);
        std::string word;

        ss >> word;
         full_name_vector.push_back(word);
        ss >> word;
         full_name_vector.push_back(word);
        ss >> word;
         full_name_vector.push_back(word);


         /*
          * Отдельные проверки на пустоту имени, фамилии, отчества
          */

         if (full_name_vector[0]==""){
             throw exceptions::ExceptionData("Имя пустое!");
         }
        first_name = full_name_vector[0];
        if (full_name_vector[1]==""){
            throw exceptions::ExceptionData("Фамилия пустая!");
        }
        last_name = full_name_vector[1];
        if (full_name_vector[2]==""){
            throw exceptions::ExceptionData("Отчество пустое!");
        }
        patronymic = full_name_vector[2];
}

void Person::setLastName(const std::string &last) {
    last_name = last;
}

void Person::setFirstname(const std::string &first) {
    first_name = first;
}

void Person::setPatronymic(const std::string &patronymic) {
    Person::patronymic = patronymic;
}




