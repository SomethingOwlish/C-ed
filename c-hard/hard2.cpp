#include "hardsource.h"
template <typename t>
void Swap(t **first, t  **second)
{
    t *temp = *first;
    *first = *second;
    *second = temp;
};

template <typename t>
void SortPointers(std::vector<t*> &v)
{
    sort(v.begin(), v.end(), [](const auto &v1, const auto &v2)
    {
        return *v1 < *v2;
    });
}

int main(){
    std::cout  << "Task 1" << '\n';
    int a = 10;
    int b = 5;
    int* first = &a;
    int* second = &b;
    std::cout << *first << " " << *second << std::endl;
    Swap(&first, &second);
    std::cout << *first << " " << *second << std::endl;
    std::cout << a << " " << b << std::endl;

    std::cout  << "Task 2" << '\n';



    std::cout  << "Task 3" << '\n';


return 0;
};


