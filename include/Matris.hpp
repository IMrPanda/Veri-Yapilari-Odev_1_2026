/** 
* @file        Matris.cpp
* @description Matris sınıfının implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        11.18.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#ifndef MATRIS_HPP
#define MATRIS_HPP

#include "HucreDugum.hpp"

class Matris {
private:
    HucreDugum* ilk;
    HucreDugum* son;
    int sutun;  
    int satir;  

public:
    Matris(int sutun, int satir);  // kurucu
    ~Matris(); // yıkıcı

    void sonaEkle(int veri); // veri ekleme
    double artOrt() const; // aritmetik ortalama hesaplama
    void yazdir() const; // yazdırma

    int getSutun() const; // sütun sayısı
    int getSatir() const; // satır sayısı
    bool MatrisBosMu() const; // matris boş mu
};

#endif