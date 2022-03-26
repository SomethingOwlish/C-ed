#include <iostream>

//Задание 1
//Для приведения булина к строке в выводе. Так интереснее чем писаnь строку в выводе в консоль просто.
inline const char * const BoolToString(bool b)
{
    return b ? "true" : "false";
}
//А теперь сама задачка
 int un41(){
    using namespace std;
     float val1 = 0, val2 = 0, sum = 0; //так как о целочисленности в условиях не было - пусть будет так.
     bool res1;
     cout << "Enter first value" << endl ;
     cin >> val1;
     cout << "Enter second value" << endl ;
     cin >> val2;
     sum = val1 + val2;

    ( 10 <= sum & sum <= 20 ) ? res1 = true : res1 = false;
    cout <<  BoolToString(res1) << endl;

     return 0;
 };

//Задание 2

int un42(){
    //в условии было определить константы сразу
    int const VAL2_1 = 3;
    int const VAL2_2 = 4;

    int sum = VAL2_1 + VAL2_2;
    bool res2;

    switch (sum){
        case 10:
        case 20: //потому что условие "Обе равны десяти сами по себе//
            res2 = true;
            break;
        default:
            res2 = false;
            break;
    }
    //Приведем булин к строке по другому и выведем результат как в условии - строкой)
    std::cout << std::boolalpha << res2 << std::endl;
    return 0;
};

//Задание 3
int un43(){
    int listOf[25];
    int i = 0, q = 0;
    while (i < 50){
        i++;
        if (i % 2 != 0) {
            listOf[q]=i;
             q++;}
        else { };}

   for (int s : listOf) {
        std::cout << s << " ";
    }
    std::cout << '\n';
    return 0;
};

//Задание 4

int un44(){
    int x; int val3 = 0;
    std::cout << "Enter value" << std::endl ;
    std::cin >> val3;

   // for (x = 2; x<=sqrt(val3); x++) {
        if (val3 % x == 0) {
            std::cout << "false" << std::endl ; //В смысле не является простым числом
            return 0;
        };


    std::cout << "true" << std::endl ; //В смысле "является простым числом"
    return 0;
};


//Задание 5

int un45(){
    using namespace std;
    int year = 0;
    bool res5;
 do {
     cout << "Enter the year" << endl;
        cin >> year;
 }
 while (year > 3000 || year < 1);

    if ((!(year % 4) && (year % 100)) || (!(year % 400)))
    {
        res5 = true;
    }
    else {
        res5 = false;
    }
    cout  << std::boolalpha << res5 << endl;
    return 0;
};


//вызов программ по очереди)
int les4(){
    std::cout  << "Task 1" << '\n';
    un41();
    std::cout  << std::endl;

    std::cout  << "Task 2" << '\n';
    un42();
    std::cout  << std::endl;

    std::cout  << "Task 3" << '\n';
    un43();
    std::cout  << std::endl;

    std::cout  << "Task 4" << '\n';
    un44();
    std::cout  << std::endl;

    std::cout  << "Task 5" << '\n';
    un45();
    std::cout  << std::endl;
    return 0;
}