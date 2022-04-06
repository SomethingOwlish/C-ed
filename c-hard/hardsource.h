//
// Created by Morgan Valravn on 26.03.2022.
//

#ifndef C_ED_HARDSOURCE_H
#define C_ED_HARDSOURCE_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <iomanip>
#include <math.h>
#include <thread>
#include <chrono>
#include <iterator>
#include <cstdint>
#include <string>
#include <sstream>
#include <optional>
#include <vector>
#include <tuple>
#include <list>
template <typename t>
void showVector( std::vector<t>a);
void showVectorLink( std::vector<int*>&a);
void showList(std::list<float>a);
class timer {
    clock_t start;
    clock_t stop;
public:
    void startTimer();
    void stopTimer();
};
#endif //C_ED_HARDSOURCE_H
