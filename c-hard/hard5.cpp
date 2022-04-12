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
//Считаем слова в предложении
int countWord(std::string line){
    int count = 1;
    std::string probel = " ";
    for (const char &c : line)
    {
        if (probel.find(c) != std::string::npos)
        {
            count++;
        };};
    return count;
};

// Закидываем в мультипам
void addLine(std::string line, std::unordered_multimap<std::string, int> &book){
   int count = countWord(line);
    book.insert(make_pair(line, count));
};

//ловим предложения
void reader (std::unordered_multimap<std::string, int> &book) {
    std::string razdelMarks{".?;!\0"};
    std::string line;
    std::cout << "Напиши End для окончания";
    while (line != "End") {
        std::string temp;
        std::getline(std::cin, line);
      for (const char &c : line) {
            temp.push_back(c);
            if (razdelMarks.find(c) != std::string::npos) {
                line.erase(0, temp.size());
                if (temp[0] == ' ') { temp.erase(0, 1); }
                addLine(temp, book);
                temp = ""; };
            };
        };
    };
};

void printBook(std::unordered_multimap<std::string, int> &book){
    for_each(book.begin(), book.end(),
             [](std::pair<std::string, int> line){
                 std::cout << line.first << " | " << line.second << "\n";
             });
};
/* Используя ассоциативный контейнер, напишите программу, которая будет считывать данные
введенные пользователем из стандартного потока ввода и разбивать их на предложения.
Далее программа должна вывести пользователю все предложения, а также количество слов в
них, отсортировав предложения по количеству слов.
 * Вывод предложений с подсчетом слов
 */


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
    std::unordered_multimap<std::string, int> book;
    reader(book);
    printBook(book);
    return 0;
};