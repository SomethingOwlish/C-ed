//
// Created by Morgan Valravn on 01.04.2022.
//
#include "hardsource.h"
// Задание 1
template<typename T, typename V>
void insert_sorted(V &spisok, T znach){
    //Хотя в задаче сказано что список уже сортирован, на всякий случай прогоняю доп. сортировку в конце.
   spisok.insert(spisok.begin(),znach);
   int s = spisok.size();
   std::nth_element(spisok.begin(), spisok.begin(), spisok.end());
   sort(spisok.begin(), spisok.end());
};
// Задание 2
void anToCif(){
    std::vector<float> analog(100);
    generate (analog.begin(), analog.end(), [](){return (rand()*(100.00-1.00)/RAND_MAX+1.00);});
    std::vector<int> cifr(100);
    transform(analog.begin(), analog.end(), cifr.begin(), [](float i){ return static_cast<int>(i);});

    std::cout << "Вектор для аналоговых"  << std::endl;
    copy(analog.begin(), analog.end(), std::ostream_iterator<float>{std::cout, ", "});
    std::cout << "Вектор для цифровых"  <<std::endl;
    copy(cifr.begin(), cifr.end(), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;

    float error = 0;
    for_each(analog.begin(), analog.end(), [&](const double &i)
    {
        error += pow(i - static_cast<int>(i), 2);
    });
    std::cout << "Errors: " << error << std::endl;
}

int mainh4(){
    srand(time(0));
    std::cout  << "Task 1" << '\n';
    std::vector<int> taskOne;
    for (int i = 1; i < 10; i++) {
        taskOne.push_back(rand() % 100 +1);
    };
    int tskZnach = rand() % 100 +1;
    for (auto n : taskOne) std::cout << n << " ";
    std::cout << "\n" << tskZnach << std::endl;
    insert_sorted(taskOne, tskZnach);
    for (auto n : taskOne) std::cout << n << " ";
    std::cout << std::endl;
    std::cout  << "Task 2" << '\n';
    anToCif();
    return 0;
};