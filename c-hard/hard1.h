//
// Created by Morgan Valravn on 17.04.2022.
//

#ifndef C_ED_HARD1_H
#define C_ED_HARD1_H

struct Person {
    std::string firstName;
    std::string lastName;
    std::optional<std::string> fatherName;
    friend bool operator<(const Person& p1, const Person& p2);
    friend bool operator==(const Person& p1, const Person& p2);
    friend std::ostream& operator<< (std::ostream &out, const Person &p);
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

class PhoneBook {
private:
public:
    std::vector<std::pair<Person, PhoneNumber>> bookPh;

    friend std::ostream &operator<<(std::ostream &out, const PhoneBook &p);
    PhoneBook(std::vector<std::pair<Person, PhoneNumber>> a);
    PhoneBook(std::ifstream &file);
    void SortByPhone();
    void SortByName() ;
    std::pair<std::string, std::vector<PhoneNumber>> GetPhoneNumber(const std::string &fathername);
    void ChangePhoneNumber(const Person &p, const PhoneNumber &pn);
    };

int mainh1();

#endif //C_ED_HARD1_H
