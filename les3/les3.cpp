#include <iostream>

//задание 1

int ex1() {
    const int a = 3, b = 4, c = 7, d = 2;
    float res;
float step1, step2;

step1 = static_cast<float>(c)/static_cast<float>(d);
step2 = static_cast<float>(b) + step1;
res = a * step2;

    std::cout << res << std::endl;
    return 0;
}

//Задание 2

int ex2 (){
    int num, res2, preRes2;
    res2 = (num <= 21) ? 21 - num : 2*(num-21);
    std::cout << res2 << std::endl;
    return 0;
}


//Задание 3
/* Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива и при помощи
 операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1]. */

int ex3 (){
    int * pArr = nullptr;
int res3;
int arr[3][3][3]{};
//Мне было лень заполнять руками, поэтому будет так:
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            arr[i][j][k] = (i + 1) * 100 + (j + 1) * 10 + (k + 1);}}}

pArr = & arr[1][1][1];
res3 = *pArr;
    std::cout << res3 << std::endl; //вывод тут сделан для самопроверки - внизу есть вызовы=)
return 0;
}


/*задание 4
 Для удобства a, b,, c, d заменено на q, w, e, r соответственно
*/

int ex4() {
    extern const int  q;
    extern const int w;
    extern const int e;
    extern const int r;

    float res4;
    float step4_1, step4_2;

    step4_1 = static_cast<float>(e)/static_cast<float>(r);
    step4_2 = static_cast<float>(w) + step4_1;
    res4 = q * step4_2;

    std::cout << res4 << std::endl;
    return 0;
}


//вызовы звдвний для проверки
int main(){
    ex1 ();
    ex2 ();
    ex3 ();
    ex4 ();
}