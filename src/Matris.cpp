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

    // ----------------------------------
    // çoklu eleman olursa 
    this->toplam = 0;      
    this->elemanSayisi = 0; 
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
    toplam += veri;
    elemanSayisi++;

}

double Matris::artOrt() const {
    if (elemanSayisi == 0) return 0.0;
    return static_cast<double>(toplam) / elemanSayisi;
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

// -----------------------------------------------
// dosya kaydet
void Matris::dosyaYaz(ostream& out) const {
    out << sutun << " " << satir;
    HucreDugum* gec = ilk;
    while (gec != nullptr) {
        out << " " << gec->veri;
        gec = gec->sonraki;
    }
    out << "\n";
}

// -------------------------------------------------
// matrisi komple sil
HucreDugum* Matris::hucreGetir(int r, int c) const {
    int hedefIndex = r * sutun + c;
    HucreDugum* gec = ilk;
    for (int i = 0; i < hedefIndex && gec != nullptr; i++) {
        gec = gec->sonraki;
    }
    return gec;
}

void Matris::dugumKompleSil(HucreDugum* hedef) {
    if (hedef == nullptr) return;

    if (hedef->onceki != nullptr) {
        hedef->onceki->sonraki = hedef->sonraki;
    } else {
        ilk = hedef->sonraki;
    }

    if (hedef->sonraki != nullptr) {
        hedef->sonraki->onceki = hedef->onceki;
    } else {
        son = hedef->onceki;
    }

    toplam -= hedef->veri; 
    elemanSayisi--;        

    delete hedef;
}


// -------------------------------------------------------
// matris işlemleri 
void Matris::satirSil(int silinecekSatir) {
    if (satir <= 0 || silinecekSatir < 0 || silinecekSatir >= satir) return;

    HucreDugum* gec = hucreGetir(silinecekSatir, 0);
    for (int c = 0; c < sutun && gec != nullptr; c++) {
        HucreDugum* silinecek = gec;
        gec = gec->sonraki;
        dugumKompleSil(silinecek);
    }

    satir--;
    if (satir == 0) sutun = 0;
}

void Matris::sutunSil(int silinecekSutun) {
    if (sutun <= 0 || silinecekSutun < 0 || silinecekSutun >= sutun) return;

    // Sondan başa siliyoruz ki üstteki satırların indeksleri kaymasın
    for (int r = satir - 1; r >= 0; r--) {
        HucreDugum* hedef = hucreGetir(r, silinecekSutun);
        dugumKompleSil(hedef);
    }

    sutun--;
    if (sutun == 0) satir = 0;
}

bool Matris::satirSutunDegistir(int satirNo, int sutunNo) {
    if (satirNo < 0 || satirNo >= satir || sutunNo < 0 || sutunNo >= sutun) {
        return false;
    }

    int limit = (satir < sutun) ? satir : sutun;
    for (int i = 0; i < limit; i++) {
        HucreDugum* h1 = hucreGetir(satirNo, i);
        HucreDugum* h2 = hucreGetir(i, sutunNo);
        if (h1 != nullptr && h2 != nullptr) {
            int gecici = h1->veri;
            h1->veri = h2->veri;
            h2->veri = gecici;
        }
    }
    return true;
}

void Matris::yazdirSeciliSatir(int seciliSatir) const {
    HucreDugum* gec = ilk;
    for (int r = 0; r < satir; r++) {
        for (int c = 0; c < sutun && gec != nullptr; c++) {
            cout << setw(4) << gec->veri;
            gec = gec->sonraki;
        }
        if (r == seciliSatir) {
            cout << "   <---";
        }
        cout << endl;
    }
}

void Matris::yazdirSeciliSutun(int seciliSutun) const {
    for (int c = 0; c < sutun; c++) {
        if (c == seciliSutun) {
            cout << setw(4) << "v";
        } else {
            cout << setw(4) << " ";
        }
    }
    cout << endl;
    yazdir();
}