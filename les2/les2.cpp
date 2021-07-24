#include <iostream>

// задание 1
short int var1 = 0;
int var2 = 0;
long long var3 = 0;
char var4 = 'S';
bool var5 = false;
float var6 = 2.22f;
double var7 = 64.679;

// задание 2
enum gameSymbols {
    E, // = empty
    X,
    O
};

// задание 3

    char sToUse[3] = {E, X, O};

// задание 4
struct pl
{char symbol;
    std::string name;};
bool isStart;

 struct field {
   char fi[3][3] = {{E, E, E}, {E, E, E}, {E, E, E}};
pl playerX;
pl playerO;
char whoesTurn; //Предполагается идентификация пользователя по полю символ, то есть либо Х либюо О, а не по номерам)
short int turnCount;
bool haveAWinner;
bool haveEmptyField; // Позволяте закончить игру по признаку отсутствия чистых полей, без победителя
// И скорее всего понадобятся эти штуки
bool isPl1Win;
bool isPl2Win;
 };


// задание 5



int les2() {
    struct whatIf {
        union log {
            int phone;
            float id;
            char userFirstChar;
        };
        unsigned int isInt: 1;
        unsigned int isFloat: 1;
        unsigned int isChar: 1;

    };
    return 0;
};