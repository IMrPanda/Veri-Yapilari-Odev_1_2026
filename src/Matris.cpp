/** 
* @file        Matris.cpp
* @description Matris sınıfının implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "Matris.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Matris::Matris(int sutun, int satir) {  // kurucu
    this->ilk = nullptr;
    this->son = nullptr;
    this->sutun = sutun;
    this->satir = satir;
}

Matris::~Matris() { // yıkıcı
    HucreDugum* gec = ilk;
    while (gec != nullptr) {
        HucreDugum* silinecek = gec;
        gec = gec->sonraki;
        delete silinecek;
    }
}

void Matris::sonaEkle(int veri) { // veri ekleme
    HucreDugum* yeni = new HucreDugum(veri);
    if (ilk == nullptr) {
        ilk = yeni;
        son = yeni;
    } else {
        son->sonraki = yeni;
        yeni->onceki = son;
        son = yeni;
    }
}

double Matris::artOrt() const {
    if (ilk == nullptr) return 0.0;

    long long toplam = 0;
    int adet = 0;
    HucreDugum* gec = ilk;
    while (gec != nullptr) {
        toplam += gec->veri;
        adet++;
        gec = gec->sonraki;
    }
    return static_cast<double>(toplam) / adet;
}

void Matris::yazdir() const {
    HucreDugum* gec = ilk;
    int sayac = 0;
    while (gec != nullptr) {
        cout << setw(4) << gec->veri;
        sayac++;
        if (sayac % sutun == 0) {
            cout << endl;
        }
        gec = gec->sonraki;
    }
}

int Matris::getSutun() const { return sutun; }
int Matris::getSatir() const { return satir; }
bool Matris::MatrisBosMu() const { return ilk == nullptr; }