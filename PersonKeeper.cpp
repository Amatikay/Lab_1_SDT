//
// Created by sergey on 15.03.2022.
//

#include <fstream>
#include <iostream>
#include "PersonKeeper.h"
#include "Stack.h"
#include "Person.h"
#include "Exception.h"


Stack<Person> PersonKeeper::readPersons(std::string file_path) {
    std::string s;
    std::ifstream file(file_path,std::ios_base::in);
    if (!file.is_open()){
        /*
         * я сначала передавал
         * в readPersons(const char* file_path)
         * конструкцию менять не стал
         */
        std::string buf("Файл ");
        buf.append(file_path);
        buf.append(" не открылся");
        throw exceptions::ExceptionFile(buf.c_str());
    }

    while(getline(file, s)){ //"file >> ..." не сработает тк, считывает до первого пробела. Я считываю всю строку и разбиваю на подстроки
        if (s =="" /*std::string::npos*/){
            file.close();
            throw exceptions::ExceptionData("Пустая строка");
        }

        if ((count(s.begin(), s.end(), ' '))!=2){
            file.close();
            throw exceptions::ExceptionData("В полученной строке не 3 слова");
        }

        Person FIO(s);
        PersonKeeper::Instance().PersonStack.Push(FIO);
    }

    file.close();

    return PersonKeeper::Instance().PersonStack;

}
void PersonKeeper::writePersons(std::string file_path) {

    std::ofstream file(file_path, std::ios::trunc); // открываем файл. удаялем все содержимое
    if (!file.is_open()){

        /*
         * Как и в readPersons
         */
        std::string buf("Файл ");
        buf.append(file_path);
        buf.append(" не открылся");
        throw exceptions::ExceptionFile(buf.c_str());

    }
    /*
     *Передаю указатель на верхушку стека.
     * Считываю person и записываю в файл не меняя стек.
     */
    Person person;
    Node<Person>* p;
    p = PersonKeeper::Instance().PersonStack.get_topPtr();
    while(p!=nullptr){
        person = p->item ;
        file << person.getFirstName() << " " << person.getLastName() << " " << person.getPatronymic() << "\n";
        p=p->next;
    }
}