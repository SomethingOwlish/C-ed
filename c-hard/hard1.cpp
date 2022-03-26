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
    out  << p.lastName << ", " << p.firstName << " " << p.fatherName.value_or("") << " ";
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

struct PhoneNumber{
    int countryCode;
    int cityCode;
    std::string number;
    std::optional<int> addNumber;
    friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
    friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);
    friend std::ostream& operator<< (std::ostream &out, const PhoneNumber &p);
};
std::ostream& operator<< (std::ostream &out, const PhoneNumber &p){
    std::string addN = std::to_string(p.addNumber.value_or(0));
    out  << p.countryCode << "(" << p.cityCode << ")" <<  p.number << " " << addN;
    return out;
};
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.addNumber) <
           tie(p2.countryCode, p2.cityCode, p2.number, p2.addNumber);
};
bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.addNumber) <
           tie(p2.countryCode, p2.cityCode, p2.number, p2.addNumber);
};


class PhoneBook{
private:
    std::vector<std::pair<Person, PhoneNumber>> bookPh;
public:
    friend std::ostream& operator<< (std::ostream &out, const PhoneBook &p);
    PhoneBook(std::ifstream & file){
        this->bookPh.clear();
        if(file.is_open()){
            int s = 0;
            int bookSize = 1;
            while(!file.eof()) {
                std::string fName;
                std::string lName;
                std::string faName;
                std::string cCode;
                std::string ciCode;
                std::string num;
                std::string addNum;
                std::string temp;

                file >> fName  >> lName >> temp;

                int n = temp.length();
                char chAr[n + 1];
                strcpy(chAr, temp.c_str());

                if (std::isalpha(chAr[0])){
                    faName = temp;
                    file >> cCode;
                } else {
                    cCode = temp;
                };

                file >> ciCode >> num >> temp;

                if ( temp == "/n"){

                } else {
                    addNum = temp;
                };

                Person tempPerson {lName, fName, faName};
                std::cout << tempPerson;
                PhoneNumber tempPhone {atoi(cCode.c_str()),atoi(ciCode.c_str()),num,atoi(addNum.c_str())};
                std::pair<Person, PhoneNumber> tempPair(tempPerson, tempPhone);

                bookPh.resize(bookSize);
                bookSize++;


                bookPh[s] = tempPair;
                s++;
            };

        file.close();
        };
    };



};
std::ostream& operator<< (std::ostream &out, const PhoneBook &p) {
    for (const auto&[person, phone] : p.bookPh) {
        out << person << " " << phone << std::endl;
    };

    return out;
};



int main(){
using namespace std;
    ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
     cout << book;
       cout << "------SortByPhone-------" << endl;
     /*      book.SortByPhone();
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
