#include "hardsource.h"
/* 1. Написать функцию, добавляющую в конец списка вещественных чисел
элемент, значение которого равно среднему арифметическому всех его
элементов.
2. Создать класс, представляющий матрицу. Реализовать в нем метод,
вычисляющий определитель матрицы. Для реализации используйте
контейнеры из STL.
3. Реализовать собственный класс итератора, с помощью которого можно будет
проитерироваться по диапазону целых чисел в цикле for-range-based.
 */
void addToEnd (std::list<float> *l){
float count = 0;
float sum = 0;
float middle;
    for (float value : *l) {
        sum += value;
        count ++;
    };
 middle = sum/count;
 l->push_back(middle);
};

void randValforList(std::list<float> *l){
    int size = rand() % 10 +5;
    for(size; size >0; size--) {
    float val = 1 + rand() % 10;
    l->push_back(val);
};};


int main(){
    srand(time(0));
    std::cout  << "Task 1" << '\n';
    std::list<float> taskOne;
    randValforList(&taskOne);
    showList(taskOne);
    addToEnd(&taskOne);
    showList(taskOne);

    std::cout  << "Task 2" << '\n';

    return 0;
};