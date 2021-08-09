#include <iostream>

int ask(){
    int par;
    std::cout << "Введите число" << std::endl;
    std::cin >> par;
    return par;
};

std::string askStr(){
    std::string par;
    std::cout << "Введите..." << std::endl;
    std::cin >> par;
    return par;
};


int printMass(double* mas, int sun1){

    for (int i = 0; i < sun1; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << '\n';
    return 0;
};

int printMass(int* mas, int s ){
    for (int i = 0; i <  s; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << '\n';
    return 0;
};

int printMassBig(int **mas, int s, int w ){
    for (int i = 0; i <  s; i++){
        for (int k = 0; k <  w; k++) {
        std::cout << mas[i][k] << " ";
    } std::cout << '\n';};
    return 0;
};