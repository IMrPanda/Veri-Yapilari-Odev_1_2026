/** 
* @file        Uygulama.hpp
* @description Konsol uygulamasının başlık dosyası. AnaListe ve DosyaYoneticisi sınıflarını kullanarak matrisleri yönetir.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        20.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "Uygulama.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

Uygulama::Uygulama(const string& dosyaAdi) { // kurucu
    this->dosyaAdi = dosyaAdi;
    this->liste = new AnaListe();
    this->dosyaYoneticisi = new DosyaYoneticisi();

    dosyaYoneticisi->dosyadanOku(dosyaAdi, liste);
    this->seciliDugum = liste->getIlk();
    this->seciliIndex = (seciliDugum != nullptr) ? 0 : -1;
}

Uygulama::~Uygulama() { // yıkıcı
    delete dosyaYoneticisi;
    delete liste;
}

void Uygulama::yukariGit() { 
    if (seciliDugum != nullptr && seciliDugum->onceki != nullptr) {
        seciliDugum = seciliDugum->onceki;
        seciliIndex--;
    }
}

void Uygulama::asagiGit() { 
    if (seciliDugum != nullptr && seciliDugum->sonraki != nullptr) {
        seciliDugum = seciliDugum->sonraki;
        seciliIndex++;
    }
}

void Uygulama::anaEkraniGoster() const {
    system("cls");

    if (liste->ListeBosMu() || seciliDugum == nullptr) {
        cout << "Listede hic matris yok." << endl;
        return;
    }

    int sayfaBaslangic = (seciliIndex / 5) * 5;
    ListeDugum* gec = liste->dugumGetir(sayfaBaslangic);

    cout << "=== MATRIS LISTESI (Sayfa " << (seciliIndex / 5) + 1
         << " | Toplam: " << liste->getDugumSayisi() << ") ===" << endl << endl;

    int sayac = 0;
    while (gec != nullptr && sayac < 5) {
        bool seciliMi = (gec == seciliDugum);

        cout << " +----------------------+" << endl;
        cout << " | Adres  : " << setw(11) << gec << " |"
             << (seciliMi ? "  <--- SECILI" : "") << endl;
        cout << " | Ort    : " << setw(11) << fixed << setprecision(2) << gec->matris->artOrt() << " |" << endl;
        cout << " | Sonraki: " << setw(11) << gec->sonraki << " |" << endl;
        cout << " +----------------------+" << endl;

        gec = gec->sonraki;
        sayac++;
    }

    cout << endl << "=== SECILI MATRIS ("
         << seciliDugum->matris->getSutun() << "x" << seciliDugum->matris->getSatir()
         << ") ===" << endl;
    seciliDugum->matris->yazdir();

    cout << endl << "[W] Yukari  [S] Asagi  [Q] One Ekle  [E] Arkaya Ekle  [F] Matris Islem  [X] Kaydet ve Cik" << endl;
    cout << "Seciminiz: ";
}

void Uygulama::calistir() {
    char secim;
    while (true) {
        anaEkraniGoster();
        cin >> secim;
        secim = static_cast<char>(tolower(static_cast<unsigned char>(secim)));

        if (secim == 'w') {
            yukariGit();
        } else if (secim == 's') {
            asagiGit();
        } else if (secim == 'x') {
            break; 
        }
    }
}