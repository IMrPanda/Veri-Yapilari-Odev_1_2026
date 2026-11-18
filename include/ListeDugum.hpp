/** 
* @file        ListeDugum.hpp
* @description çift yönlü bağlı listede Matris tutan düğüm sınıfının başlık dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#ifndef LISTEDUGUM_HPP
#define LISTEDUGUM_HPP

#include "Matris.hpp"

class ListeDugum {
public:
    Matris* matris; 
    ListeDugum* sonraki; 
    ListeDugum* onceki;

    ListeDugum(Matris* matris); // kurucu
    ~ListeDugum(); // yıkıcı
};

#endif