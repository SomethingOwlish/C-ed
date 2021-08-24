#include <iostream>
#include <random>
// Это общая функция запроса какого-нибудь числа, она маленькая так что я ее заинлайнила ради опыта
int ask5(){
    int par;
    std::cout << "Введите число" << std::endl;
    std::cin >> par;
    return par;
};


//Задание 1
// Тут функция вывода, кторую потом в майне вызовем
int printMass5(double* mas, int sun1){

    for (int i = 0; i < sun1; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << '\n';
    return 0;
};
// Тут в рамках идеи о перегрузке функции такая же но под инт, так как в задании 2 понадобится
int printMass5(int* mas, int s ){
    for (int i = 0; i <  s; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << '\n';
    return 0;
};


//Задание 2
/* Задать целочисленный массив, состоящий из элементов 0 и 1.
 * Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
 * Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0.
 * Выводить на экран массив до изменений и после.
*/
// Тут в начале функция вывода массивов под int


int changeMas(int* mas, int q) {
    int perebor; // переменная для переора значений
    for (int i = 0; i < q; i++) {
        perebor = mas[i];
        /*Вообще-то можно было иф/элс но я переписала на свитч когда дебажила
         * так как не понимала где ошибка (была вообще не тут -
         * в передаче массива обратно), и так и оставила*/
        switch (perebor) {
            case 0:
                mas[i] = 1;
                break;
            case 1:
                mas[i] = 0;
                break;
        };

    }
    return 0;
}

int un52(){
    int s = rand() % 25 +5; //Тут переменная для размера массива и рандомный размер массива в диапазоне от 5 до 25 (что бы не мало и не много)

    int un2list[s];

//Тут генератор рандома, потому что мне лень да и при  рандомном размере как-то иначе не вижу удобного способа заполнить

    for (int i = 0; i < s; i++){
        un2list[i] = 0 + rand() % 2;
    };
// Выводим на экран что есть
    printMass5(un2list, s);
// Вызываем функцию замены
    changeMas(un2list, s);
    // Печатаем новую версию
    printMass5(un2list, s);
    return 0;
};
//Задание 3
//Решила записать массив и передать из массива в массив - так эе проще кажется)

int un53(int* ar, int s){
    int un3Val[8] = {1, 4, 7, 10, 13, 16, 19, 22};
    for (int i = 0; i < s; i++){
        ar[i] = un3Val[i];
    }; // Тут только сама функция, печать вызывается в майне)
    return 0;
};

//Задание 4

int un54(int*  list, int q, int move){

    if (move < 0) {
        move = move * -1;
        for (int cir = move; cir > 0; cir++) {
            int tmp = list[q-1];
            for (int i = q-1; i > 0; i--) {
                list[i] = list[i - 1];
            }
            list[0] = tmp;
        }
    }
    else if (move > 0) {
        for (int cir = move; cir > 0; cir--) {
            int tmp = list[0];
            for (int i = 0; i < q; i++) {
                list[i] = list[i + 1];
            }
            list[q - 1] = tmp;
        }
    } else{
        std::cout << "Error! can't switch for 0" << std::endl;

    }

    return 0;
};

//Задание 5  не сделала


//вызов по очереди)
int main5(){
    std::cout  << "Task 1" << '\n';
    //Задание 1, та часть что в майне
    int s = ask5(); // Запрашиваем размер массива
    srand (time(0));
    double mas[s];     // Создаем нужный массив
    //Теперь генерируем рандомные значения
    for (int i = 0; i < s; i++){
        mas[i]= ( fabs(sin(rand())) * 40 - 14 ) ;
    }
    // А теперь вызов )
    printMass5(mas, s);
    std::cout  << std::endl;

    std::cout  << "Task 2" << '\n';
    un52();
    std::cout  << std::endl;

    int un3List[8];
    std::cout  << "Task 3" << '\n';
    un53(un3List, 8);
    printMass5(un3List, 8); //снова пользуюсь старой для печати
    std::cout  << std::endl;

    std::cout  << "Task 4" << '\n';
    int s4 = 2 + rand() % 10; // потому что меньше 2 элементов в массиве - что двигать то?
    int move = ask5(); // Запрашиваем на сколько будет сдвиг
    int un4List[s4];
    for (int i = 0; i < s4; i++){
        un4List[i]= ( rand() %100 );// Пусть будет массив случайных чисел но не больше ста, а то длинные
    }

    printMass5(un4List, s4); // Вызываем получившийся массив
    un54(un4List, s4, move);
    printMass5(un4List, s4); // а теперь со сдвигом дл япроверки
    std::cout  << std::endl;


    return 0;
};
