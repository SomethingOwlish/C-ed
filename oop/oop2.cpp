#include <iostream>
#include <cmath>
#include <cstdint>
#include "source.h"
// задание 1
class Person{


protected:
    std::string name;
    int age;
    double weight;

public:
    void setName(std::string name){
        this->name = name;
    };
    void setAge(int age){
        this->age = age;
    };
    void setWeight(double weight ){
        this->weight = weight;
    };
};

class Student : public Person{
    int yearOfSt;
    static int studentCounter;

public:


    void setYear(int year){
        this->yearOfSt = year;
    };
    void yearPlus(int plus = 1){
        this->yearOfSt = yearOfSt + plus;
    }
    std::string getName(){
        return name;
    };
    int getAge(){
        return age;
    };
    double getWeight(){
        return weight;
    };
    int getYearOf(){
        return yearOfSt;
    };
    static void addCount(){
     studentCounter++;
    }
    static void setCounter(int number){
        studentCounter = number;
    }

    Student(std::string name ="Jhon Daw", int age = 18, double weight = 82, int startYear = 1){
        addCount();
        setName(name);
        setAge(age);
        setWeight(weight);
        this->yearOfSt = startYear;

    };

};
// Инициализация счетика
int Student::studentCounter = 0;
// Красивая функция печать
void printStudent(Student student){
    std::cout << "Name: " << student.getName() << " Age: " << student.getAge()
    << " Weight: " << student.getWeight() << " Year: " << student.getYearOf() << std::endl;
}
//Задание 2

class fruit{

protected:
    std::string name;
    std::string colour;
public:
    void setName(std::string name){
        this->name = name;
    };

    void setColour(std::string col){
        this->colour = col;
    };

    virtual std::string getName(){
       return this->name;
    };

    virtual std::string  getColour(){
        return this->colour;
    };
};

class Apple : public fruit{

public:
    void setNameAp(std::string name){
        fruit::setName(name);
    };
    void setColourAp(std::string col){
        fruit::setColour(col);
    };
    virtual std::string getName(){
        return this->name;
    };

    virtual std::string  getColor(){
        return this->colour;
    };
    Apple(std::string col = "weird", std::string name = ""){
        setName(name +"apple");
        setColour(col);
    }

};

class Banana : public fruit{

    public:
    void setNameBn(std::string name){
        fruit::setName(name);
    };
    void setColourBn(std::string col){
        fruit::setColour(col);
    };
    virtual std::string getName(){
        return this->name;
    };

    virtual std::string  getColor(){
        return this->colour;
    };

    Banana(std::string col = "yellow"){
        setName("banana");
        setColour(col);
    }
};

class GrannySmith : Apple {

    public:
    std::string getName(){
        return this->name;
    };

     std::string  getColor(){
        return this->colour;
    };

    GrannySmith(std::string color = "green"){
        Apple();
        setName("GrannySmith apple");
        setColour(color);
    };
};

void un2_2(){
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
};

//задание 3

class Collection {
static int numberOdDeck;
public:
    static void addDeck(){
        numberOdDeck++;
    };
    static int getDecksNumber() {
        return numberOdDeck;
    };
};

int Collection::numberOdDeck = 0;

class Card : public Collection{
 int pointFromCard;
 std::string cardName;
 std::string cardColor;
 public:
    int getPointsFromCard(){
        return pointFromCard;
    };
    std::string getCardName(){
        return cardName;
    };
    std::string getCardColor(){
        return cardColor;
    }
    Card(std::string name, std::string col, int point){
        this->pointFromCard = point;
        this->cardColor = col;
        this->cardName = name;
    };
};


class Persons {
std::string Name;
protected:
    void setName(std::string name){
        this->Name = name;
}
public:
    std::string getName(){
        return Name;
    }
};

class Diler : public Persons{
bool insurance;
    int countCart;
    int points;
public:
    void setCounter(int countCart){
        this->countCart = countCart;
    };
    void setPoints(int point){
        this->points = point;
    };
    void setInsurance (bool i){
        this->insurance = i;
    }
    void addCart(int point){
        this->countCart = countCart++;
        this->points = points + point;
    };
    int getCounter (){
        return countCart;
    }
    int getPoints(){
        return points;
    }
    int getInsurance(){
        return insurance;
    }
    Diler(std::string name = "diler"){
        this->insurance = false;
        this -> countCart = 0;
        this-> points = 0;
        setName(name);
    }
};

class Player : public Persons {
int position;
bool haveSplit;
int stavka;
//разные виды доп ставок - если сделана то будет учитываться дальшеж
bool PP;
bool jackpot;
bool hiLo;
bool bonus;
public:
    void setPosition(int position){
        this->position = position;
    };
    void setSplit(bool split){
        this->haveSplit = split;
    };
    void setStavka(int stavka){
        this->stavka = stavka;
    };
    void setPP(bool PP){
        this->PP = PP;
    }
    void setJack(bool jack){
        this->jackpot = jack;
    }
    void setHilo(bool HiLo){
        this->hiLo = HiLo;
    }
    void setBonus(bool bonus) {
        this->bonus = bonus;
    };
Player(std::string name = "unknown",  int stavka = 100,  int position = 1){
    this->position = position;
    this-> haveSplit = false;
    this->stavka = stavka;
    this->PP = false;
    this->jackpot = false;
    this->hiLo = false;
    this->bonus = false;
    setName(name);
};
};

class PlayerHand : public Player {
int countCart;
int points;
public:
    void setCount(int count){
        this->countCart = count;
    };
    void setPoints(int points){
        this->points = points;
    }
    int getPoints(){
        return points;
    }
    int getCountCard(){
        return countCart;
    }
    PlayerHand(std::string name = "unknown", int stavka = 100, int points = 0, int count = 0, int position = 1){
        this->countCart = count;
        this->points = points;
      setName(name);
        setStavka(stavka);
        setPosition(position);
    }
    void addCart(int points = 1){
        this->points = this->points +points;
        this->countCart = countCart++;
    }
};


int main(){
//Тут хранится код, что бы проверить себя по задачам наглядной работой
    std::cout  << "Task 1" << '\n';

  Student Jea("Jean", 17, 80, 1);
  Student Mike("Mike",21,92,3);
  Student Unknown;
    printStudent(Mike);
    printStudent(Unknown);

    std::cout  << std::endl;
    std::cout  << "Task 2" << '\n';
    un2_2();
    std::cout  << std::endl;

    return 0;
}


