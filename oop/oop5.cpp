#include "source.h"
template <class T>
class Pair1{
private:
    T fVal;
    T sVal;
public:
    Pair1<T>(T a, T b){
    fVal = a;
    sVal = b;
};
    T first(){
        return fVal;
    };
    T second(){
        return sVal;
    };
};

template <class T, class B>
class Pair{
private:
    T fVal;
    B sVal;
public:
    Pair<T, B>(T a, B b){
        fVal = a;
        sVal = b;
    };
    T first(){
        return fVal;
    };
    B second(){
        return sVal;
    };
};




int mainoop5(){
    srand(time(0));
    std::cout  << "Task 1" << '\n';
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    std::cout  << "Task 2" << '\n';
    Pair<int, double> p12(6, 7.8);
    std::cout << "Pair: " << p12.first() << ' ' << p12.second() << '\n';
    const Pair<double, int> p22(3.4, 5);
   // std::cout << "Pair: " << p22.first() << ' ' << p22.second() << '\n';

    std::cout  << "Task 3" << '\n';
//    StringValuePair<int> svp(nullptr, nullptr, "Amazing", 7);
//    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
};