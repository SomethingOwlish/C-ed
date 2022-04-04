
#include "hardsource.h"

template <typename t>
void showVector( std::vector<t>a)
{
    for (typename std::vector<t>::iterator it = a.begin() ; it!=a.end() ; ++it)
        std::cout << *it;
};

void showVectorLink(std::vector<int*>&a)
{
    for (auto & it : a)
    { std::cout << *it << " ";};
    std::cout << std::endl;
};

void showList(std::list<float>a){
    for (float & it : a) {
        std::cout << it << " ";;
};
    std::cout << std::endl;
};

    void timer::startTimer(){
        start = clock();
    };

    void timer::stopTimer(){
        stop = clock();
        std::cout << "Time: " << stop - start << std::endl;
    };
