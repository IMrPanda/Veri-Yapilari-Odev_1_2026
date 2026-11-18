/** 
* @file        HucreDugum.cpp
* @description Bağıl liste düğüm yapısını tutan sınıf implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "HucreDugum.hpp"

HucreDugum::HucreDugum(int veri) {
    this->veri = veri;
    this->sonraki = nullptr;
    this->onceki = nullptr;
}