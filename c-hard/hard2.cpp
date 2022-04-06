#include "hardsource.h"
template <typename t>
void swap(t **first, t  **second)
{
    t *temp = *first;
    *first = *second;
    *second = temp;
};

template <typename t>
void sortPointers(std::vector<t*> &v)
{
    sort(v.begin(), v.end(), [](const auto &v1, const auto &v2)
    {
        return *v1 < *v2;
    });
};




std::string toFind = "AEIOUaeiou";
void fWay(std::string file)
{   timer time;
    time.startTimer();
    size_t count = std::count_if(file.begin(), file.end(), [&](const auto &c)
    {
        return toFind.find(c) != std::string::npos;
    });
    std::cout << count << std::endl;
    time.stopTimer();
}

void sWay(std::string file)
{  timer time;
    time.startTimer();
    size_t count = count_if(file.begin(), file.end(), [&](const auto &c)
    {
        for (size_t i = 0; i < toFind.size(); ++i)
        {
            if (toFind[i] == c)
                return true;
        }
        return false;
    });
    std::cout << count << std::endl;
    time.stopTimer();
}

void tWay(std::string file)
{    timer time;
    time.startTimer();
    size_t count = 0;
    for (size_t i = 0; i < file.size(); ++i)
    {
        if (toFind.find(file[i]) != std::string::npos)
        {
            ++count;
        }
    }
    std::cout << count << std::endl;
    time.stopTimer();
}

void foWay(std::string file)
{    timer time;
    time.startTimer();
    size_t count = 0;
    for (size_t i = 0; i < file.size(); ++i)
    {
        for (size_t j = 0; j < toFind.size(); ++j)
        {
            if (toFind[j] == file[i])
                ++count;
        }
    }
    std::cout << count << std::endl;
    time.stopTimer();
};


int mainh2(){
    std::srand(0);
    std::cout  << "Task 1" << '\n';
    int a = rand() % 10 +1;
    int b = rand() % 10 +1;
    int* first = &a;
    int* second = &b;
    std::cout << *first << " " << *second << std::endl;
    swap(&first, &second);
    std::cout << *first << " " << *second << std::endl;
    std::cout << a << " " << b << std::endl;

    std::cout  << "Task 2" << '\n';
    int c = rand() % 10 +1;
    int d = rand() % 10 +1;
    int* third = &c;
    int* fourth = &d;
    std::vector<int*> taskTwo = {first, second, third, fourth};
    showVectorLink(taskTwo);
    sortPointers(taskTwo);
    showVectorLink(taskTwo);

    std::cout  << "Task 3" << '\n';
    std::ifstream file;
    std::string s;
   file.open("WarAndPeace.txt");
    if (file.is_open()) {
        while(!file.eof()){
            getline(file, s);};
    } else {
        std::cout << "Error with file" << std::endl;
    }
    file.close();

    fWay(s);
    sWay(s);
    tWay(s);
    foWay(s);
return 0;
};


