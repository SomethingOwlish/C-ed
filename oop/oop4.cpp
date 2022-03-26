#include <cmath>
#include "source.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <cassert>


//Задание 1
#ifndef ARRAYINT_H
#define ARRAYINT_H
class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { };

    ArrayInt(int length):

    m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    };

    ~ArrayInt()
    {
        delete[] m_data;
    };

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    };

    int getLength() {
        return m_length;
    };

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    };

    void resize(int newLength)
    {
        if (newLength == m_length){
            return;}
        if (newLength <= 0)
        {
            erase();
            return;};
        int *data = new int[newLength];
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        };
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    };

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length+1];
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];
        data [index] = value;
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    };

    void push_back(int value) {
        insertBefore(value, m_length);
    };
//тут кончается методичка
    void popBack()
    {
        if (m_length == 0)
            return;
        resize(m_length - 1);
    }
    void popFront()
    {
        if (m_length == 0)
            return;
        if (m_length - 1 == 0)
        {
            erase();
            return;
        }
        int *data = new int[m_length - 1];
        for (int i=1; i < m_length ; ++i){
            data[i - 1] = m_data[i];
        };
        delete[] m_data;
        m_data = data;
        --m_length;
    };
    void mSort(int a, int b)
    {
        int x = m_data[(a + b) / 2];

        do
        {
            while (m_data[a] < x)
            {a++;};
            while (m_data[b] > x)
            {b--;};

            if (a <= b)
            {
                std::swap(m_data[a], m_data[b]);
                a++;
                b--;
            }
        } while (a <= b);

        if (a < b) mSort(a, b);
        if (a < b) mSort(a, b);
    };
    int printArray(int* ar, int s ){
        for (int i = 0; i <  s; i++) {
            std::cout << ar[i] << " ";
        }
        std::cout << '\n';
        return 0;
    };

};

#endif


//Задание 2
std::vector<int> randomVector(size_t size)
{
    std::vector<int> v(size);
    std::random_device r;
    generate(v.begin(), v.end(), [&]{return -10+rand()%20;});
    return v;
};




//Задание 3

class Card{
public:
enum mast{
    Cgervi,
    Bubi,
    Trefi,
    Kresti,
    havent
};
enum znach{
    no,
    tuz,
    dva,
    three,
    chetyre,
    pyat,
    six,
    seven,
    eight,
    nine,
    ten,
    valet,
    dama,
    korol
};
private:
bool position;
znach zna;
mast m;
public:
bool Flip(){
    position = !position;
};
std::string GetValue(int znach){

    if (znach == 0)
        std::cout << "no card";
    else if (znach == 1)
        std::cout << "Tuz";
    else if (znach == 2)
        std::cout << "2";
    else if (znach == 3)
        std::cout << "3";
    else if (znach == 4)
        std::cout << "4";
    else if (znach == 5)
        std::cout << "4";
    else if (znach == 5)
        std::cout << "4";
    else if (znach == 6)
        std::cout << "6";
    else if (znach == 7)
        std::cout << "7";
    else if (znach == 8)
        std::cout << "8";
    else if (znach == 9)
        std::cout << "9";
    else if (znach == 10)
        std::cout << "10";
    else if (znach == 11)
        std::cout << "Valet";
    else if (znach == 12)
        std::cout << "Queen";
    else if (znach == 13)
        std::cout << "King";
    else
        std::cout << "Who knows!";
};
int getValue() const{
    int res = zna;
    if (res > 10)
    {
        res = 10;
    }
    return res;
};

};
class Hand{
private:
    std::vector<Card*> cards;

public:
    void addCard(Card* card) {
        int size = cards.size();
        size++;
        cards.resize(size);
        cards[size] = card;
    };
 void clear(){
     cards.clear();
 }
 int getValueTotal(){
     if (cards.empty())
     {
         return 0;
     };
     int size = cards.size();
     int res= 0;
     std::vector<Card*>::const_iterator i;
     for ( i = cards.begin(); i != cards.end(); ++i){
         res += (*i)->getValue();
     };
     bool Ace = false;
     for (i = cards.begin(); i != cards.end(); ++i)
     {
         if ((*i)->getValue() == Card::tuz)
         {
             Ace = true;
         };
     };
     if (Ace && res <= 11)
     {
         res += 10;
     };
return res;
 };
};

int main4oop(){
//Тут хранится код, что бы проверить себя по задачам наглядной работой

    std::cout  << "Task 2" << '\n';
    std::vector<int> v(randomVector(30));
    std::set<int> s(v.begin(), v.end());
    std::cout << s.size() << " различных значений из " << v.size() << std::endl;
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));//выводится для самопроверки
    std::cout  << std::endl;

    return 0;
}
