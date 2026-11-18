/** 
* @file        HucreDugum.cpp
* @description Bağıl liste düğüm yapısını tutan sınıf implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        11.18.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#ifndef HUCREDUGUM_HPP
#define HUCREDUGUM_HPP

class HucreDugum {
public:
    int veri;
    HucreDugum* sonraki;
    HucreDugum* onceki;

    HucreDugum(int veri);
};

#endif