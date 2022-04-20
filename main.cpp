#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "PersonKeeper.h"
#include <vector>
#include <sstream>
int main() {

    PersonKeeper &with_good_data = PersonKeeper::Instance();
    with_good_data.readPersons("./../FIO_good_data.txt");
    with_good_data.writePersons("./../output.txt");

    PersonKeeper &with_not_full_fio = PersonKeeper::Instance();
    with_not_full_fio.readPersons("./../text1");
    with_not_full_fio.writePersons("./../output.txt");

    PersonKeeper &with_empty_row = PersonKeeper::Instance();
    with_empty_row.readPersons("./../text2");
    with_empty_row.writePersons("./../output.txt");

    PersonKeeper &with_file_not_open = PersonKeeper::Instance();
    with_file_not_open.readPersons("./../text3"); // такой файл не существует
    with_file_not_open.writePersons("./../output.txt");
}