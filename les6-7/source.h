
#ifndef C_ED_SOURCE_H
#define C_ED_SOURCE_H
#include <iostream>

int ask();
std::string askStr();
int printMass(double* mas, int sun1);
int printMass(float* mas, int sun1);
int printMass(int* mas, int s );
int printMassBig(int **mas, int s, int x );
void create (int* masCr,int x);
void create (float* masCre,int x);
namespace srce {
    void randIncFloat (float* mas,int x);
int count (float* masCou,int x);
}
#endif //C_ED_SOURCE_H
