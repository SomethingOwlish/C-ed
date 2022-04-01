#include "hardsource.h"
/*
3. Реализовать собственный класс итератора, с помощью которого можно будет
проитерироваться по диапазону целых чисел в цикле for-range-based.
 */
void addToEnd (std::list<float> *l){
float count = 0;
float sum = 0;
float middle;
    for (float value : *l) {
        sum += value;
        count ++;
    };
 middle = sum/count;
 l->push_back(middle);
};

void randValforList(std::list<float> *l){
    int size = rand() % 10 +5;
    for(size; size >0; size--) {
    float val = 1 + rand() % 10;
    l->push_back(val);
};};

class Iterator
{
private:
    double *current;
public:
    Iterator(double *pointer): current(pointer)
    {
    };
    double& operator[](size_t i)
    {
        return *(current + i);
    };
    Iterator& operator ++(){
        ++current;
        return *this;
    };
    bool operator !=(const Iterator &iterator){
        return current != iterator.current;
    };
    double& operator *(){
        return *current;
    };
};



class matrix{
private:
    const size_t mSize;
    const size_t mCapacity;
    double *array;
    double mDeterminant { 0.0 };

    matrix getModifiedMatrix(matrix &arr, const size_t item){

        matrix newMatrix(arr.size() - 1);
        size_t currentRow = 0;

        for (size_t i = 0; i < arr.size(); ++i)
        {
            if (item == i)
            {
                currentRow = i;
                continue;
            };

            for (size_t j = 0; j < newMatrix.size(); ++j)
            {
                newMatrix[currentRow][j] = arr[i][j + 1];
            };

            ++currentRow;
        };

        return newMatrix;} ;
    double calculateDeterminant(matrix &arr) {
        double determinant = 0;

        if (arr.size() == 1)
        {
            determinant = arr[0][0];
        }
        else if (arr.size() == 2)
        {
            determinant = arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
        }
        else
        {
            int sign = 1;

            for (size_t i = 0; i < arr.size(); ++i)
            {
                matrix newMatrix = getModifiedMatrix(arr, i);
                determinant += sign * arr[i][0] * calculateDeterminant(newMatrix);
                sign = -sign;
            }
        }

        return determinant;
    };
public:
    matrix(const int size): mSize(size), mCapacity(size * size)
        {
            array = new double[mCapacity];

    };

    Iterator operator[](size_t i){
        return Iterator(array + i * mSize);
    };
    Iterator begin()
    {
        return Iterator(array);
    };
    Iterator end()
    {
        return Iterator(array + mCapacity);
    };
    void mRandom(){
        for (size_t i = 0; i < mCapacity; ++i)
        {   float  val= rand() % 10 +5;
            *(array + i) = val;
        }

        mDeterminant = calculateDeterminant((*this));
    };
    void printMatrix() {
        std::cout << '[';

        for (size_t i = 0; i < mCapacity;)
        {
            std::cout <<  std::setw(5) << *(array + i++);

            if (!(i % mSize))
            {
                std::cout << " ]" <<  std::endl;

                if (i < mCapacity)
                {
                    std::cout << '[';
                };
            }
            else
            {
                std::cout << ',';
            };
        };

    };
    size_t size() const {
        return mSize;
    };
    double determinant() const {
        return mDeterminant;
    };
    ~matrix()
    {
        delete[] array;
    }

};

class iterarorTask3{


};

int main(){
    srand(time(0));
    std::cout  << "Task 1" << '\n';
    std::list<float> taskOne;
    randValforList(&taskOne);
    showList(taskOne);
    addToEnd(&taskOne);
    showList(taskOne);

    std::cout  << "Task 2" << '\n';
    size_t i = rand() % 7 +1;;
    for (i; i < 8; ++i)
    {   matrix m(i);
        m.mRandom();
        std::cout << "Matrix" << i << 'x' << i << ':' << std::endl;
        m.printMatrix();
        std::cout << "Determinant: " << std::setprecision(10) << m.determinant() << "\n\n";
        m.~matrix();
    };
    std::cout  << "Task 3" << '\n';
    matrix m(4);
    m.mRandom();

    for (const double &i : m)
    {
        std::cout << std::setw(5) << i;
    }

    std::cout << std::endl;
    return 0;
};