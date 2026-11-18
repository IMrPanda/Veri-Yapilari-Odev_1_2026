/** 
* @file        AnaListe.cpp
* @description AnaListe sınıfının implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "AnaListe.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

AnaListe::AnaListe() { // kurucu
    ilk = nullptr;
    son = nullptr;
    dugumSayisi = 0;
}

AnaListe::~AnaListe() { // yıkıcı
    ListeDugum* gec = ilk;
    while (gec != nullptr) {
        ListeDugum* silinecek = gec;
        gec = gec->sonraki;
        delete silinecek; // matris delete
    }
}

void AnaListe::ortGoreEkle(Matris* matris) { 
    ListeDugum* yeni = new ListeDugum(matris);
    double yeniOrt = matris->artOrt();

    if (ilk == nullptr) { // liste boşsa
        ilk = yeni;
        son = yeni;
    } else if (yeniOrt <= ilk->matris->artOrt()) { // yeni düğüm ort <= ilk liste ort 
        yeni->sonraki = ilk;
        ilk->onceki = yeni;
        ilk = yeni;
    } else if (yeniOrt >= son->matris->artOrt()) { // yeni düğüm ort >= son liste ort
        son->sonraki = yeni;
        yeni->onceki = son;
        son = yeni;
    } else {									 // yeni düğüm ort > ilk liste ort ve < son liste ort 
        ListeDugum* gec = ilk->sonraki;
        while (gec != nullptr && gec->matris->artOrt() < yeniOrt) { // yeni düğümün konumuna kadar git
            gec = gec->sonraki; 
        } 
        ListeDugum* oncekiDugum = gec->onceki;  // yeni düğümün ekleneceği konumun bir önceki düğümü
        oncekiDugum->sonraki = yeni; 
        yeni->onceki = oncekiDugum; 
        yeni->sonraki = gec;
        gec->onceki = yeni;
    }
    dugumSayisi++; // yeni düğüm eklendi
}

void AnaListe::ozetYazdir() const { 
    ListeDugum* gec = ilk;
    int sira = 1;
    while (gec != nullptr) {
        cout << sira << ". Dugum: " << gec
             << " | Sonraki: " << gec->sonraki
             << " | Boyut: " << gec->matris->getSutun() << "x" << gec->matris->getSatir()
             << " | Ort: " << fixed << setprecision(2) << gec->matris->artOrt() 
             << endl;
        gec = gec->sonraki;
        sira++;
    }
}

ListeDugum* AnaListe::getIlk() const { return ilk; }
ListeDugum* AnaListe::getSon() const { return son; }
int AnaListe::getDugumSayisi() const { return dugumSayisi; }
bool AnaListe::ListeBosMu() const { return ilk == nullptr; }