//
// Created by Morgan Valravn on 27.07.2021.
//

/* Изучить самостоятельно бинарный формат BMP (24 или 32 bit).
 * Он относительно простой. Создать небольшую произвольную картинку из черного и белого цветов
 * (24 или 32 бита). Написать свою программу-декодер котрая открывает и читает этот
 * BMP файл и выводит символами в консоль эту картинку.
 * (Вместо белого один символ, вместо черного цвета другой). 😎☺️*/


#include <iostream>
#include "bitmap_image.hpp"
#include "EasyBMP_1.06/EasyBMP.h"

int mainCh(){
    bitmap_image image("cat.bmp");
// Картинку в массив?

// Массив вывести побитно на экран?


    /*

             SetPixel(hDC, x, y, pBits[y * bmpInfo.bmWidth + x]);
         */
    return 0;
}