#include <cmath>
#include <cstdint>
#include "source.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
//Задание 1


//Задание 2
std::vector<int> randomVector(size_t size)
{
    std::vector<int> v(size);
    std::random_device r;
    generate(v.begin(), v.end(), [&]{return -10+rand()%20;});
    return v;
};




//Задание 3
class Hand{


};
int main(){
//Тут хранится код, что бы проверить себя по задачам наглядной работой
    std::cout  << "Task 1" << '\n';


    std::cout  << std::endl;
    std::cout  << "Task 2" << '\n';
    std::vector<int> v(randomVector(30));
    std::set<int> s(v.begin(), v.end());
    std::cout << s.size() << " различных значений из " << v.size() << std::endl;
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout  << std::endl;
    std::cout  << "Task 3" << '\n';

    std::cout  << std::endl;
    return 0;
}
