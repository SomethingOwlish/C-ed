#include <iostream>
#include <cmath>


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
    double getA() const{
        return this->a;
    };
    double getH() const{
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
    Parallelogram()= default;
Parallelogram(double a, double h){
    setA(a);
    setH(h);
};
    double area() override{
        S = getA() * getH();
        return S;
    };

};
class Rectangle : public Parallelogram {
public:

    Rectangle(double a, double h){
        setA(a);
        setH(h); };
    double area() override{
        S = (getA()/2) * getH();
        return S;
    };
};
class  Square: public Parallelogram {
public:
    Square(double a){
        setA(a);
    };
    double area() override{
        S = pow(getA(),2);
        return S;
    };
};

class Rhombus : public Parallelogram {
public:
  Rhombus(double a, double h){
      setA(a);
      setH(h);  };
    double area() override{
        S = getA() * getH();
        return S;
    };
};
class Circle : public Figure {
private:
    double r;

public:
  void  setR(double a){
        this->r= a;
    };
  double getR() const
    {return r;
    };

 Circle(double r){
 setR(r);
 };

 double area() override{
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
   void  setCompany(std::string com){
        this->company = com;
    };
    void  setModel(std::string mod){
        this->model = mod;
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

//Задание 3
int nodF(int a, int b){
    if (a % b == 0){
        return b;} else
    if (b % a == 0){
        return a;} else
    if (a > b){
        return (a%b, b);} else
{ return (a, b%a);};
};
int lcm(int a, int b){
    return (a*b)/nodF(a,b);
}
class Fraction{
private:
 int numerator;
 int denominator;
    void cut(){

int nod = nodF(numerator, denominator);
       numerator /= nod;
       denominator /= nod;

        };
    double toReal() const{
        return double(numerator)/denominator;
    };
public:
    void setNumerator (int a){
        this->numerator = a;
    };
    void setDenominator (int b){
        this->denominator = b;
    };
    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const
    {
return denominator;
    };

    Fraction(int a, int b){
        if (b == 0){
            assert(b == 0);
        } else {
        setNumerator(a);
        setDenominator(b);
        ;};
};
    Fraction(int a){
        setNumerator(a);
        setDenominator(1);
    };
Fraction(std::string a){
    assert(a.empty());
    int p = a.find('/');
    if (p == a.npos) {
        setNumerator(stoi(a));
        setDenominator(1);
    }else {
        setNumerator(stoi(a.substr(0, p)));
        setDenominator( stoi(a.substr(p, a.length())));
        assert(denominator == 0);
    }};
    Fraction& operator+(const Fraction &fr){
        int uniond = lcm(denominator, fr.getDenominator());
        int rel = numerator * fr.getDenominator();
        int mul = fr.numerator * denominator;
        numerator = rel + mul;
        denominator = uniond;
        std::cout << std::to_string(getNumerator()) <<" " << std::to_string(getDenominator());
        cut();
        return *this;
    };
    Fraction& operator-(const Fraction &fr){
        numerator = numerator * fr.getDenominator() - denominator * fr.getNumerator();
        denominator = nodF(denominator, fr.getDenominator());
        cut();
        return *this;
    };
    Fraction& operator*(const Fraction &fr){
        numerator = numerator * fr.getNumerator();
        denominator = denominator * fr.getDenominator();
        cut();
        return *this;
    };
    Fraction& operator/(const Fraction &fr){
        numerator = numerator * fr.getDenominator();
        denominator = denominator * fr.getNumerator();
        cut();
        return *this;
    };
    bool operator==(const Fraction &fr) const  {
        return numerator == fr.numerator && denominator == fr.denominator;
    };
    bool operator!=(const Fraction &fr) const {
        return !(*this == fr);
    };
    bool operator>=(const Fraction &fr) const {
        return *this > fr || *this == fr;
    }

    bool operator<(const Fraction &fr) const {
        return toReal() < fr.toReal();
    }

    bool operator<=(const Fraction &fr) const {
        return *this < fr || *this == fr;
    }

    bool operator>(const Fraction &fr) const {
        return toReal() > fr.toReal();
    };
    void operator-(){
        numerator = -numerator;
    };

    std::string  getFraction()
    {
        std::string numSt = std::to_string(getNumerator());
        std::string denSt = std::to_string(getDenominator());
        std::string dFr =   numSt+"/"+denSt;
        return dFr;
    };
};
//задание 4

class Card {
private:
    bool position;
    enum mast{
        Cgervi,
        Bubi,
        Trefi,
        Kresti,
        havent
    };
    enum znach{
        no,
        tuz,
        dva,
        three,
        chetyre,
        pyat,
        six,
        seven,
        eight,
        nine,
        ten,
        valet,
        dama,
        korol
    };
public:
    bool Flip(){
    position = !position;
};
std::string GetValue(int znach){

        if (znach == 0)
            std::cout << "no card";
        else if (znach == 1)
            std::cout << "Tuz";
        else if (znach == 2)
            std::cout << "2";
        else if (znach == 3)
            std::cout << "3";
        else if (znach == 4)
            std::cout << "4";
        else if (znach == 5)
            std::cout << "4";
        else if (znach == 5)
            std::cout << "4";
        else if (znach == 6)
            std::cout << "6";
        else if (znach == 7)
            std::cout << "7";
        else if (znach == 8)
            std::cout << "8";
        else if (znach == 9)
            std::cout << "9";
        else if (znach == 10)
            std::cout << "10";
        else if (znach == 11)
            std::cout << "Valet";
        else if (znach == 12)
            std::cout << "Queen";
        else if (znach == 13)
            std::cout << "King";
        else
            std::cout << "Who knows!";
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
    std::cout  << "Task 3" << '\n';
    Fraction drOne(3,7);
    Fraction drTwo(2,6);
    bool drFiTest = drOne == drTwo;
    bool drTwTest = drOne > drTwo;
    std::string drThTest = drOne.getFraction();
    drOne + drTwo;
    std::string drFrTest = drOne.getFraction();
    drOne / drTwo;
    std::string drSiTest = drOne.getFraction();
    -drOne;
    std::string drSeTest = drOne.getFraction();
    std::cout   << '\n' << drFiTest << '\n';
    std::cout   << drTwTest  << '\n';
    std::cout   << drThTest  << '\n';
    std::cout   << drFrTest  << '\n';
    std::cout   << drSiTest  << '\n';
    std::cout   << drSeTest  << '\n';
    return 0;
}
