/** 
* @file        AnaListe.hpp
* @description Matris nesnelerini aritmetik ortalamalarına göre küçükten büyüğe sıralı tutan 
*              çift yönlü bağlı liste sınıfının başlık dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#ifndef ANALISTE_HPP
#define ANALISTE_HPP

#include "ListeDugum.hpp"

class AnaListe {
private:
    ListeDugum* ilk;
    ListeDugum* son;
    int dugumSayisi;

public:
    AnaListe(); // kurucu
    ~AnaListe(); // yıkıcı

    void ortGoreEkle(Matris* matris); // matrisleri aritmetik ortalamalarına göre sıralı ekleme
    void ozetYazdir() const;

    ListeDugum* getIlk() const;
    ListeDugum* getSon() const;
    int getDugumSayisi() const;
    bool ListeBosMu() const;
};

#endif