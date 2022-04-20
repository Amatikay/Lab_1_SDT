//
// Created by sergey on 22.03.2022.
//
#include <string>
#include "Person.h"
#include <iostream>
#include <vector>
#include <sstream>
Person::Person(const std::string full_name) {




    try {
        std::vector<std::string> full_name_vector;
        std::istringstream ss(full_name);
        std::string word;



       /* do{
            full_name_vector.push_back(word);
        }while (ss >> word);*/
       /*
        * Отчество не отделяется закоментированным
        * способом. Разобраться почему
        */
        ss >> word;
         full_name_vector.push_back(word);
        ss >> word;
         full_name_vector.push_back(word);
        ss >> word;
         full_name_vector.push_back(word);



        first_name = full_name_vector[0];
        last_name = full_name_vector[1];
        patronymic = full_name_vector[2];

    }
    catch (...) {
        /*
         * TODO
         *  Тут нужно расписать возможные исключения:
         *  Фамилия и(или) Имя и(или) Отчество не введены
         *  (строка имеет не 3 подстроки разделенные пробелами)
         *  Пустая строка (std::string::npos)
         *  В строке больше "слов", чем 3.
         *
         *  Это может вызвать некоторые проблемы, такие как имена изх нескольки слов
         *  " Ксения Хаджы Оглы (Отчество) "
         *  Возможно проще будет создать метод, куда буду передавать фио отдельными аргументами
         *
         *
         */
        std::cout << "Ошибка с данными" << std::endl;
        throw;
    }


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

