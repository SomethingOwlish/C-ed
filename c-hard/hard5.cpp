//
// Created by Morgan Valravn on 06.04.2022.
//
#include "hardsource.h"
//Задание 1
template <typename It>
void countUniq(It first, It last){
    std::unordered_set<std::string> uniqWords(first, last);
    std::cout << "Список уникальных слов:" << std::endl;
    copy(uniqWords.begin(), uniqWords.end(), std::ostream_iterator<std::string>{std::cout, "\n"});
};
//Задание 2



int main(){
    srand(time(0));
    std::cout  << "Task 1" << '\n';
    std::vector<std::string> VectorfWord {"Кот", "Пес", "Кот", "Кроль", "Лиса"};
    std::list<std::string> ListOfWords {"Кот", "Пес", "Кот", "Кроль", "Лиса", "Мишка", "Пес", "Волк", "Кроль", "Лиса"};
    std::deque<std::string> DequeWords (ListOfWords.begin(), ListOfWords.end());
    countUniq(VectorfWord.begin(), VectorfWord.end());
    countUniq(ListOfWords.begin(),ListOfWords.end());
    countUniq(DequeWords.begin(), DequeWords.end());
    std::cout  << "Task 2" << '\n';

    return 0;
};