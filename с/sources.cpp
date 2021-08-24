#include <iostream>
namespace cSrce {
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
int printMass(float* mas, int sun1){

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

int printMassBig(int **mas, int s, int x ){
    for (int i = 0; i <  s; i++){
        for (int k = 0; k <  x; k++) {
            std::cout << mas[i][k] << " ";
        } std::cout << '\n';};
    return 0;
};

void create (int* masCr,int x){

    masCr = new (std::nothrow) int[x];

};

void create (float* masCre,int x){
    int size = x;
    masCre = new (std::nothrow) float[size];

};

    void randIncFloat (float* mas,int x) {
        srand(time(0));
        for (int i = 0; i < x; i++) {
            mas[i] = rand() % 100 + 1;
        };
    };
    int count (float* masCou,int x ){
        int counted, chet = 0, nChet = 0;
        for (size_t i = 0; i < x; i++){
            counted = masCou[i];
            if (counted % 2 == 0) {
                chet += 1;
            } else {
                nChet += 1;
            };
        };
        std::cout << chet << " " << nChet; // Здесь сделан вывод что бы знать сколько насчитали
        return 0;
    };};