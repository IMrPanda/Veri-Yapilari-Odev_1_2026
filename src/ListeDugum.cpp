/** 
* @file        ListeDugum.cpp
* @description çift yönlü bağlı listede Matris tutan düğüm sınıfının implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "ListeDugum.hpp"

ListeDugum::ListeDugum(Matris* matris) { // kurucu
    this->matris = matris;
    this->sonraki = nullptr;
    this->onceki = nullptr;
}

ListeDugum::~ListeDugum() { // yıkıcı
    delete matris;
}