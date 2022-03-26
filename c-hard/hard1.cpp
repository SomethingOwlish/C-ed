#include "hardsource.h"


struct Person {
    std::string firstName;
    std::string lastName;
    std::optional<std::string> fatherName;
 friend bool operator<(const Person& p1, const Person& p2);
 friend bool operator==(const Person& p1, const Person& p2);
 friend std::ostream& operator<< (std::ostream &out, const Person &p);

};

std::ostream& operator<< (std::ostream &out, const Person &p){
    out  << p.lastName << ", " << p.firstName << p.fatherName.value_or("");
    return out;
};

bool operator<(const Person& p1, const Person& p2)
{
    return tie(p1.firstName, p1.lastName, p1.fatherName) <
           tie(p2.firstName, p2.lastName, p2.fatherName);
};
bool operator==(const Person& p1, const Person& p2)
{
    return tie(p1.firstName, p1.lastName, p1.fatherName) <
           tie(p2.firstName, p2.lastName, p2.fatherName);
};

struct PhoneNumber;
class PhoneBook{

};




int main(){
/*
    ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
// лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };
// вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
                           PhoneNumber{7, 123, "15344458", nullopt});
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
                           PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book; */
};
