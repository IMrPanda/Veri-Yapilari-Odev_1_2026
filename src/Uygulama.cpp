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
#include <ctime>


using namespace std;

Uygulama::Uygulama(const string& dosyaAdi) { // kurucu
    this->dosyaAdi = dosyaAdi;
    this->liste = new AnaListe();
    this->dosyaYoneticisi = new DosyaYoneticisi();

    dosyaYoneticisi->dosyaOku(dosyaAdi, liste);
    this->seciliDugum = liste->getIlk();
    this->seciliIndex = (seciliDugum != nullptr) ? 0 : -1;

    // ----------------------------------------------
    // rastgele sayı 
    srand(static_cast<unsigned int>(time(nullptr)));
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

// ----------------------------------------------
// matris ekleme ve silme

Matris* Uygulama::rastgMatrisUret() const {
    int sutun = (rand() % 9) + 2; 
    int satir = (rand() % 9) + 2; 

    int* havuz = new int[100];
    for (int i = 0; i < 100; i++) {
        havuz[i] = i; // 0-99 arası
    }

    // karıştır
    for (int i = 99; i > 0; i--) {
        int j = rand() % (i + 1);
        int gecici = havuz[i];
        havuz[i] = havuz[j];
        havuz[j] = gecici;
    }

    Matris* yeni = new Matris(sutun, satir);
    int toplamEleman = sutun * satir;
    for (int i = 0; i < toplamEleman; i++) {
        yeni->sonaEkle(havuz[i]);
    }

    delete[] havuz;
    return yeni;
}

void Uygulama::eklendiEkrani(ListeDugum* yeniDugum) const {
    system("cls");

    int sayfaBaslangic = (seciliIndex / 5) * 5;
    ListeDugum* gec = liste->dugumGetir(sayfaBaslangic);

    cout << "=== MATRIS LISTESI (Sayfa " << (seciliIndex / 5) + 1
         << " | Toplam: " << liste->getDugumSayisi() << ") ===" << endl << endl;

    int sayac = 0;
    while (gec != nullptr && sayac < 5) {
        string etiket = "";
        if (gec == seciliDugum) {
            etiket = "  <--- SECILI";
        } else if (gec == yeniDugum) {
            etiket = "  <--- YENI EKLENDI";
        }

        cout << " +----------------------+" << endl;
        cout << " | Adres  : " << setw(11) << gec << " |" << etiket << endl;
        cout << " | Ort    : " << setw(11) << fixed << setprecision(2) << gec->matris->artOrt() << " |" << endl;
        cout << " | Sonraki: " << setw(11) << gec->sonraki << " |" << endl;
        cout << " +----------------------+" << endl;

        gec = gec->sonraki;
        sayac++;
    }

    cout << endl << "=== YENI EKLENEN MATRIS ("
         << yeniDugum->matris->getSutun() << "x" << yeniDugum->matris->getSatir()
         << " | Adres: " << yeniDugum
         << " | Ort: " << fixed << setprecision(2) << yeniDugum->matris->artOrt()
         << ") ===" << endl;
    yeniDugum->matris->yazdir();

    cout << endl << "Devam etmek icin Enter'a basin...";
}

void Uygulama::onMatrisEkle() {
    Matris* yeniMatris = rastgMatrisUret();
    ListeDugum* yeniDugum = liste->onEkle(seciliDugum, yeniMatris);
    seciliIndex = liste->indexBul(seciliDugum);

    eklendiEkrani(yeniDugum);
    cin.get();

    liste->ortGoreSirala();
    seciliIndex = liste->indexBul(seciliDugum);
}

void Uygulama::arkaMatrisEkle() {
    Matris* yeniMatris = rastgMatrisUret();
    ListeDugum* yeniDugum = liste->arkaEkle(seciliDugum, yeniMatris);
    seciliIndex = liste->indexBul(seciliDugum);

    eklendiEkrani(yeniDugum);
    cin.get();

    liste->ortGoreSirala();
    seciliIndex = liste->indexBul(seciliDugum);
}

// ----------------------------------------------
// konsol ekranı

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
    bool devam = true;

    while (devam) {
        anaEkraniGoster();
        cin >> secim;
        cin.ignore(1000, '\n'); // birden fazla input alınmasın
        secim = static_cast<char>(tolower(static_cast<unsigned char>(secim)));

        switch (secim) {
            case 'w':
                yukariGit();
                break;
            case 's':
                asagiGit();
                break;
            case 'q':
                onMatrisEkle();
                break;
            case 'e':
                arkaMatrisEkle();
                break;
            case 'f':
                // matris islemleri
                break;
            case 'x':
                dosyaYoneticisi->dosyaKaydet(dosyaAdi, liste);
                cout << "Veriler " << dosyaAdi << " dosyasina kaydedildi. Cikiliyor..." << endl;
                devam = false;
                break;
            default:
                break;
        }
    }
}