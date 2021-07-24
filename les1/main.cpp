#include <iostream>
//комментарий

int main1() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}



/* большой комментарий
 Что бы прям все*/
// cin из лекции
int main2() {
    using namespace std;
    cout << "Enter your name: ";
    char name [32] = { 0 };
    cin >> name; // пользователь вводит свое имя
    cout << "Enter your age: ";
    unsigned int age = 0;
    cin >> age; // пользователь вводит свой возраст
    cout << "Hi, " << name << "_" << age << endl;

    return 0;
}