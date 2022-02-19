#include <iostream>
#include <cmath>
#include <cstdint>
#include "source.h"

//Задание 1
class Figure{
protected:
    double S;
    double a;
    double h;
    const double P = 3.14;
public:
    virtual double area() = 0;
    double getP() const{
        return this->P;
    };
    double getA(){
        return this->a;
    };
    double getH(){
        return this->h;
    }
};

class Parallelogram : public Figure {
public:
    void setA(double a){
        this->a = a;
    };
    void setH(double h){
        this->h = h;
    };
    Parallelogram(){


};
Parallelogram(double a, double h){
    setA(a);
    setH(h);
};
    virtual double area(){
        S = getA() * getH();
        return S;
    };

};
class Rectangle : public Parallelogram {
public:

    Rectangle(double a, double h){
        setA(a);
        setH(h); };
    virtual double area(){
        S = (getA()/2) * getH();
        return S;
    };
};
class  Square: public Parallelogram {
public:
    Square(double a){
        setA(a);
    };
    virtual double area(){
        S = pow(getA(),2);
        return S;
    };
};

class Rhombus : public Parallelogram {
public:
  Rhombus(double a, double h){
      setA(a);
      setH(h);  };
    virtual double area(){
        S = getA() * getH();
        return S;
    };
};
class Circle : public Figure {
private:
    double r;

public:
  void  setR(double r){
        this->r= r;
    };
  double getR()
    {return r;
    };

 Circle(double r){
 setR(r);
 };

 virtual double area(){
        S = getP() * (pow(getR(), 2));
        return S;
    };
};
//Задание 2
class Car {
private:
    std::string company = "default";
    std::string model = "default";
public:
   void  setCompany(std::string company){
        this->company = company;
    };
    void  setModel(std::string model){
        this->model = model;
    }
     std::string getCompany() {
        return company;
    };
    std::string getModel() {
        return model;
    };
    Car() {
           std::cout << "Company:" << getCompany() << std::endl;
           std::cout << "Model:" << getModel() << std::endl;
    };
    Car(std::string model, std::string company){
        setCompany(company);
        setModel(model);
        std::cout << "Company:" << getCompany() << std::endl;
        std::cout << "Model:" << getModel() << std::endl;
    };
};

class PassengerCar : virtual public Car {
public:
PassengerCar() {
    std::cout << "Company:" << getCompany() << std::endl;
    std::cout << "Model:" << getModel() << std::endl; };
PassengerCar(std::string model, std::string company){
setCompany(company);
setModel(model);
std::cout << "Company:" << getCompany() << std::endl;
std::cout << "Model:" << getModel() << std::endl;
};
};

class Bus: virtual  public Car {
public:
    Bus() {     std::cout << "Company:" << getCompany() << std::endl;
        std::cout << "Model:" << getModel() << std::endl; };
Bus (std::string model, std::string company){
setCompany(company);
setModel(model);
std::cout << "Company:" << getCompany() << std::endl;
std::cout << "Model:" << getModel() << std::endl;
};
};

class Minivan: private PassengerCar, private Bus{
public:
    Minivan() {     std::cout << "Company:" << getCompany() << std::endl;
        std::cout << "Model:" << getModel() << std::endl; };
    Minivan (std::string model, std::string company){
        setCompany(company);
        setModel(model);
        std::cout << "Company:" << getCompany() << std::endl;
        std::cout << "Model:" << getModel() << std::endl;
    };
};


int main(){
//Тут хранится код, что бы проверить себя по задачам наглядной работой
    std::cout  << "Task 1" << '\n';
    Circle FirstTest(4);
    std::cout << FirstTest.area() << std::endl;
    Parallelogram SecondTest(3,4);
    std::cout << SecondTest.area() << std::endl;
    Rectangle ThirdTest(5, 3);
    std::cout << ThirdTest.area() << std::endl;
    Square FourthTest(7);
    std::cout << FourthTest.area() << std::endl;
    Rhombus FifthTest(2,9);
    std::cout << FifthTest.area() << std::endl;
    std::cout  << "Task 2" << '\n';
    std::cout  << '\n'  << "Car Instanse" << '\n';
    Car one("oneTest","testOne");
    std::cout   << '\n' << "PassengerCar Instanse" << '\n';
    PassengerCar two("twoTest","testTwo");
    std::cout   << '\n' << "Bus Instanse" << '\n';
    Bus three("thteeTest", "testThree");
    std::cout   << '\n' << "Minivan Instanse" << '\n';
    Minivan four("fourTest", "tesfour");
    std::cout  << std::endl;

    return 0;
}
