#include <iostream>
#include <fstream>
#include "sourses.h"
using namespace cSrce;

void val(int* list,int sizeV); // Заполнители значений
void valFor2(int** list, int x, int y); // Заполнители значений

//Задание 1

int un61(){
    int* list;
    int size = ask(); // Количество элементов
    list = new (std::nothrow) int[size];
val(list, size);
    printMass(list, size);
    delete[] list;
    list = nullptr;
    return 0;
};

void val(int* list,int sizeV){
    int q = 1;
    for (int i = 0; i < sizeV; i++){
        list[i] = q;
        q = q*2;
    };
}
//Задание 2
void create(int **list, int x, int y);
void dell(int** list, int x, int y);
int un62(){
    const size_t x = 4;
    const size_t y = 4;
    int** list2;
    list2 = new int *[x];
    create(list2, x,y); //Создаем
    valFor2(list2,x,y); //Заполняем рандомом
    printMassBig(list2,x,y); // печатаем
    dell(list2,x,y);//Освобождаем
    return 0;
};

void create (int** list2,int x, int y){

    for (size_t i = 0; i < x; i++) {
        list2[i] = new int[y];
    }
};
void dell(int** list, int x, int y){
for (size_t i = 0; i < x; i++) {
delete [] list[i];
};
delete[] list;
list = nullptr;};

void valFor2(int** list, int x, int y){
    for (int j = 0; j < x; j++) {
        for (int k = 0; k < y; k++) {
            list[j][k] = 1 +  rand() % 100;}};
};

//Задание 3

std::string One, Two; // это переменные для 4 задачи


int un63(){
std::string nameOne = askStr();
std::string nameTwo = askStr();


    std::ofstream foutOne(nameOne+".txt");
    foutOne << "Это просто текст для теста - записывать строки удобно и прикольно, а во второй файл вооще гугл запрос " << std::endl;
    foutOne.close();

    std::ofstream foutTwo(nameTwo+".txt");
    foutTwo << "Стих, стиховедческий термин, используемый в нескольких значениях: художественная речь, организованная делением на ритмически соизмеримые отрезки; поэзия в узком смысле; в частности, подразумевает свойства стихосложения той или иной традиции;" << std::endl;
    foutTwo.close();
    // А тут подготовка под четвертую задачу

    One = nameOne+".txt";
   Two = nameTwo+".txt";
    return 0;
};

//Задание 4
int un64(){
    using namespace std;
    string nameAll = askStr(); //просим имя файла
    string tmpString;
    ofstream fout;
    fout.open(nameAll+".txt"); //открыли файл  первый раз

    if (fout.is_open()) {
        //Первый поехал - перезапишем все что было в файле
        ifstream in;
        in.open(One.c_str());
        if (in.is_open()) {
            const size_t size = 255;

            while (!in.eof()) {
                getline(in, tmpString);
                fout << tmpString << std::endl;
            }
            in.close();
        } else {
            cout << "Ошибка с файлом " + One;
        };
        fout.close();
    }
    else {cout << "Ошибка с файлом " + nameAll + " Первое открытие";};

    //Теперь на дозапись открываем
    ofstream out(nameAll+".txt", ios::app);
    if (out.is_open()) {

        //Второй поехал - дописываем
        ifstream in;
        in.open(Two.c_str());
        if (in.is_open()) {
            const size_t size = 255;

            while (!in.eof()) {

                getline(in, tmpString);
                out << tmpString << std::endl;
            }
            in.close();
        } else {
            cout << "Ошибка с файлом " + Two;
        }
        out.close();
    };
    return 0;
};



//Задание 5

int un65(){
    using namespace std;
    cout << "Надо найти ";
    string search = askStr();// Спрашиваем что искать
    cout << "в файле ";
    string fileName = askStr();// Спрашиваем где

    ifstream inFive;
    inFive.open(fileName.c_str()); // Открываем файл и погнали искать
    if (inFive.is_open()) {
        const size_t size = 255;
        string buf;
        while (!inFive.eof()) {
            getline(inFive, buf);
            if (buf.find(search) != string::npos) {
                cout << "Мы нашли " + search;
            } else {
                cout << "Нет никакого " + search;
            }
        }
    }
    inFive.close();
    return 0;
};


int main6(){
    srand (time(0));
    std::cout  << "Task 61" << '\n';
    un61();
    std::cout  << std::endl;

    std::cout  << "Task 62" << '\n';
    un62();
    std::cout  << std::endl;

    std::cout  << "Task 63" << '\n';
   un63();
    std::cout  << std::endl;

    std::cout  << "Task 64" << '\n';
   un64();
    std::cout  << std::endl;

    std::cout  << "Task 65" << '\n';
    un65();
    std::cout  << std::endl;


    return 0;
};

