//
// Created by sergey on 15.03.2022.
//

#include <fstream>
#include "PersonKeeper.h"
#include "Stack.h"
#include "Person.h"


Stack<Person> PersonKeeper::readPersons(std::string file_path) {
/*
 * TODO
 *  Нужно добавить проверки:
 *  открытия файла
 *  Корректности данных в строке (возможно я это проверю в Person.cpp)
 */



    std::string s;

    std::ifstream file;
    file.open(file_path,std::ios_base::in);

    while(getline(file, s)){ //"file >> ..." не сработате тк, считывает до первого пробела. Я считываю всю строку и разбиваю на подстроки

        Person FIO(s);
        PersonStack.Push(FIO);
    }

    file.close();

    return PersonKeeper::Instance().PersonStack;

}

void PersonKeeper::writePersons(std::string file_path) {


    /*
     * TODO
     *  Исключения для вывода стека в файл
     */


    std::ofstream file;
    file.open(file_path, std::ios::trunc);
    Person person;
    Node<Person>* p;
    p = PersonKeeper::Instance().PersonStack.get_topPtr();
    while(p!=nullptr){
        person = p->item ;
        file << person.getFirstName() << " " << person.getLastName() << " " << person.getPatronymic() << "\n";
        p=p->next;
    }
}