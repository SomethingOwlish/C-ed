#include <iostream>
#include <cmath>
#include <cstdint>
#include "source.h"  // Это мой заголовочный файл всех домашек с функциями, приложен в задаче)
using namespace oopSrce; //Так как у меня лежит в одном проекте с прошлым курсом, то разделила неймспейсами папки
void testStack();// Это нужно в самом конце

// Первое задание
    class Power {
public: //Здесь нуно ддя вызова из майна ниже
    float valOne;
    float valTwo;


        void set(float x, float y) {
            this->valOne = x;
            this->valTwo = y;
        };

        void calculate(float x= 3.14, float y= 8.8432) {
            float res = pow(x, y);
            std::cout << res << std::endl;
        };
    };


// Второе задание
 class RGBA{

     std::uint8_t m_red = 0;
     std::uint8_t m_green = 0;
     std::uint8_t m_blue = 0;
     std::uint8_t m_alpha = 255;

 public:
     RGBA(){
      //Cделала здесь конструктор по умолчанию что бы в Маине нормально себя проверять;
     };
     RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha){
         m_red = red;
         m_blue = green;
         m_green = blue;
         m_alpha = alpha;
     };
     void print(){
         std::cout << "m_red = " << (int)m_red << std::endl;
         std::cout << "m_green = " << (int)m_green << std::endl;
         std::cout << "m_blue = " << (int)m_blue << std::endl;
         std::cout << "m_alpha = " << (int)m_alpha << std::endl;
     };
 };

// Третье Задание
 class Stack{

 private:
     int* list =  new (std::nothrow) int [10];
     int counter = 0;
     bool resVal = false; //Нужно что бы вижеть что в стеке есть значения

 public:
     void reset(){
        delete [] list;
         list = nullptr; //на всякий случай совсем обнулим
         resVal = false; //Помечаем что значений нет
     };

    bool push (int x){
       if (!resVal) {
           resVal = true;
           list =  new (std::nothrow) int [10];
       } ; // Если не было ниодного значения - отмечаем что вводим первые

        bool pushRes;
        assert(counter <= 10);

         list[counter] = x;
            counter++;
            pushRes = true;

        return pushRes;
    };

   int pop (){ //вообще не поняла зачем этому методу возврат числа но в задаче было сказано что надо
        int popVal;

        if (!resVal){
            std::cout << "Стек пуст!" << std::endl;
          } else {
            popVal = list[counter];
            list[counter] = 0; //Можно и без этого, но пусть юудет нулем
            counter--;
            }
    return popVal;
     };

    void print(){
        if (!resVal){
            std::cout << "" << std::endl;
        } else {
            printMass(list, counter);
        };
    };

 };
int oop1_3(){
    //Условие из задачи - код майн  в этой функции
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
};


int main(){
//Тут хранится код, что бы проверить себя по задачам наглядной работой
    std::cout  << "Task 1" << '\n';
    Power *power;
    float un1, un2;
    un1 = ask();
    un2 = ask();
    (power->set)(un1, un2);
    (power->calculate)(power->valOne, power->valTwo);
    //(power->calculate)(); - Эта ддя вызова со значениямипо умолчанию
    std::cout  << std::endl;

    std::cout  << "Task 2" << '\n';
    RGBA oop2;
    oop2.print();
    std::uint8_t r, g, b, a;
    r = askUi();
    g = askUi();
    b = askUi();
    a = askUi();
    RGBA oop2_2(r,g,b,a);
    oop2_2.print();
    std::cout  << std::endl;

    std::cout  << "Task 3" << '\n';
    oop1_3(); //данный в задаче Майн записан в эту функцию, что бы вызывать из нее
    testStack(); // А это функция где я попробовала реализовать это же задание но через std::slack


    return 0;
}


#include <stack>

class Test{
std::stack<int> arr;

public:
    void reset(){
    while(!arr.empty()){
            arr.pop();
            }
    };

    void push(int x){
        arr.push(x);
    };

    void pop(){
        arr.pop();
    };

    void print() {
        std::stack<int> invert;

        while (!arr.empty()) {
           invert.push(arr.top());
           arr.pop();
        }

        while(!invert.empty()){
            std::cout << invert.top() << " ";
            arr.push(invert.top());
            invert.pop();
    };
        std::cout << std::endl;
};
};

void testStack(){
//    Тут код из задачи ддя проверки, только имя класса меняла
    Test testSl;
    testSl.reset();
    testSl.print();
    testSl.push(3);
    testSl.push(7);
    testSl.push(5);
    testSl.print();

    testSl.pop();
    testSl.print();

    testSl.pop();
    testSl.pop();
    testSl.print();
};