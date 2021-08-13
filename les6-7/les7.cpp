#include <iostream>
#include <fstream>

#include <string>
#include "source.h"  // Это мой заголовочный файл

//Задание 1

int un1(){
    int size = ask(); //Узнаем размер массива
    float* listForOne;
    listForOne= new (std::nothrow) float [size];
  //  create(listForOne, size);
  srce::randIncFloat(listForOne, size); //инициализирцем рандомными значениями
    printMass(listForOne, size);
    srce::count(listForOne, size);
    return 0;
};

int un2(){

#define SomeCount (0 <= n && n < s ) ? std::cout<< "True" :  std::cout<< "False"
    int n = ask();
    int s = ask();
    SomeCount;
    return 0;
};

int un3(){
#define SizeMas 7
#define SwampInt(a, b) \
   decltype(a) tmp = a; \
  a = b; \
  b = tmp;
int arrUn3[SizeMas];
    for ( int i=0; i<SizeMas; i++ ){
        std::cin >> arrUn3[i];
};

    for (int i = 0; i <= SizeMas - 1; i++) {
        for (int j = 0; j < SizeMas - 1 ; j++) {
            int s = j+1;
            if (arrUn3[j] > arrUn3[s]) {
                int a = arrUn3[j];
                int b = arrUn3[s];
                SwampInt(a, b)
                arrUn3[j] = a;
                arrUn3[s] = b;

            } else {};
        };
    }
    printMass(arrUn3, SizeMas);


    return 0;
};

int un4(){
#pragma pack(push, 1)
    struct Emp {
        int id;
        std::string name;
        int age;
        int idPosition;
        float salary;};
#pragma pack(pop)

Emp * jhon = new Emp;
jhon->id = 4322;
jhon->name="Jhon";
jhon->age = 18;
jhon->idPosition = 2342;
jhon->salary = 1500;


    std::cout << jhon->id << " " << jhon->name << " " << jhon->age << " " << jhon->idPosition << " " << jhon->salary;
    std::cout << "\n" << sizeof(jhon) << std::endl;
    std::ofstream fout("jhon.txt");
    fout << jhon->id << " " << jhon->name << " " << jhon->age << " " << jhon->idPosition << " " << jhon->salary;
    fout.close();

    return 0;
};



int main(){
    srand (time(0));
    std::cout  << "Task 1" << '\n';
   un1();
    std::cout  << std::endl;

    std::cout  << "Task 2" << '\n';
  un2();
    std::cout  << std::endl;

    std::cout  << "Task 3" << '\n';
   un3();
    std::cout  << std::endl;

    std::cout  << "Task 4" << '\n';
    un4();
    std::cout  << std::endl;




    return 0;
};

