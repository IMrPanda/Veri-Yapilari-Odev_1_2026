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

    if (seciliDugum == nullptr) seciliDugum = yeniDugum; // listede matris yoksa yeni eklenen matrisi göster
    seciliIndex = liste->indexBul(seciliDugum);

    eklendiEkrani(yeniDugum);
    cin.get();


    liste->ortGoreSirala();
    seciliIndex = liste->indexBul(seciliDugum);
}

void Uygulama::arkaMatrisEkle() {
    Matris* yeniMatris = rastgMatrisUret();
    ListeDugum* yeniDugum = liste->arkaEkle(seciliDugum, yeniMatris);

    if (seciliDugum == nullptr) seciliDugum = yeniDugum; // listede matris yoksa yeni eklenen matrisi göster
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

void Uygulama::matrisIslemMenusu() {
    bool degisiklikOldu = false;
    bool dugumSilindi = false;
    char secim;

    while (true) {
        system("cls");
        cout << "=== MATRIS ISLEM MENUSU (Adres: " << seciliDugum
             << " | Boyut: " << seciliDugum->matris->getSutun() << "x" << seciliDugum->matris->getSatir()
             << " | Ort: " << fixed << setprecision(2) << seciliDugum->matris->artOrt()
             << ") ===" << endl << endl;

        seciliDugum->matris->yazdir();

        cout << endl << "[1] Satir Sil   [2] Sutun Sil   [3] Satir-Sutun Degistir   [X] Ana Menuye Don" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        cin.ignore(1000, '\n');
        secim = static_cast<char>(tolower(static_cast<unsigned char>(secim)));

        // satır silme 
        if (secim == '1') {
            degisiklikOldu = true;
            if (satirSil()) { 
                dugumSilindi = true;
                break;
            }
            break; // ana menüye dön

        // sütun silme 
        } else if (secim == '2') {
            degisiklikOldu = true;
            if (sutunSil()) { 
                dugumSilindi = true;
                break;
            }
            break; // ana menüye dön

        // satır sütun değiştirme 
        } else if (secim == '3') {
            satirSutunDegistir();
            break; // ana menüye dön

        // ana menüye dön
        } else if (secim == 'x') {
            break; 
        }
    }

    // degisiklik olmadıysa yeniden sıralama , olduysa artOrta göre sırala
    if (degisiklikOldu && !dugumSilindi && seciliDugum != nullptr) {
        liste->ortGoreSirala();
        seciliIndex = liste->indexBul(seciliDugum);
    }
}

bool Uygulama::satirSil() {
    int seciliSatir = 0;
    char secim;

        // satır silme menusu 
    while (true) {
        system("cls");
        cout << "=== SATIR SILME (Ort: " << fixed << setprecision(2)
             << seciliDugum->matris->artOrt() << ") ===" << endl << endl;

        seciliDugum->matris->yazdirSeciliSatir(seciliSatir);

        cout << endl << "[W] Yukari   [S] Asagi   [D] Satiri Sil   [X] Ana Menuye Don" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        cin.ignore(1000, '\n');
        secim = static_cast<char>(tolower(static_cast<unsigned char>(secim)));

        switch (secim) {
            // üstteki satıra geç
            case 'w':
                if (seciliSatir > 0) seciliSatir--;
                break;
            case 's':
            // alttaki satıra geç
                if (seciliSatir < seciliDugum->matris->getSatir() - 1) seciliSatir++;
                break;
            // seçili satırı sil
            case 'd':
                seciliDugum->matris->satirSil(seciliSatir);
                // tüm satırlar silindiyse düğümü sil
                if (seciliDugum->matris->MatrisBosMu()) {
                    seciliDugum = liste->dugumSil(seciliDugum);
                    seciliIndex = (seciliDugum != nullptr) ? liste->indexBul(seciliDugum) : -1;
                    return true; // düğüm tamamen silindi
                }
                // satır varsa o satırı sil
                if (seciliSatir >= seciliDugum->matris->getSatir()) {
                    seciliSatir = seciliDugum->matris->getSatir() - 1;
                }
                break;
            // ana menüye dön
            case 'x':
                return false;
            default:
                break;
        }
    }
}

bool Uygulama::sutunSil() {
    int seciliSutun = 0;
    char secim;

        // sütun silme menüsü
    while (true) {
        system("cls");
        cout << "=== SUTUN SILME (Ort: " << fixed << setprecision(2)
             << seciliDugum->matris->artOrt() << ") ===" << endl << endl;

        seciliDugum->matris->yazdirSeciliSutun(seciliSutun);

        cout << endl << "[A] Sol   [D] Sag   [F] Sutunu Sil   [X] Ana Menuye Don" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        cin.ignore(1000, '\n');
        secim = static_cast<char>(tolower(static_cast<unsigned char>(secim)));

        switch (secim) {
            // soldaki sütuna geç
            case 'a':
                if (seciliSutun > 0) seciliSutun--;
                break;
            // sağdaki sütuna geç
            case 'd':
                if (seciliSutun < seciliDugum->matris->getSutun() - 1) seciliSutun++;
                break;
            // seçili sütunu sil
            case 'f':
                seciliDugum->matris->sutunSil(seciliSutun);
                 // tüm sütunlar silindiyse düğümü sil
                if (seciliDugum->matris->MatrisBosMu()) {
                    seciliDugum = liste->dugumSil(seciliDugum);
                    seciliIndex = (seciliDugum != nullptr) ? liste->indexBul(seciliDugum) : -1;
                    return true; // düğüm tamamen silindi
                }
                // sütun varsa o sütunu sil
                if (seciliSutun >= seciliDugum->matris->getSutun()) {
                    seciliSutun = seciliDugum->matris->getSutun() - 1;
                }
                break;
            // ana menüye
            case 'x':
                return false;
            default:
                break;
        }
    }
}

void Uygulama::satirSutunDegistir() {
    int satirNo, sutunNo;
    int maxSatir = seciliDugum->matris->getSatir();
    int maxSutun = seciliDugum->matris->getSutun();

    // sütun seç
    cout << "Degistirilecek Sutun Numarasi (1 - " << maxSutun << "): ";  
    if (!(cin >> sutunNo)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    // satır seç
    cout << "Degistirilecek Satir Numarasi (1 - " << maxSatir << "): ";
    if (!(cin >> satirNo)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    cin.ignore(1000, '\n');

    // yanlış seçim
    if (!seciliDugum->matris->satirSutunDegistir(satirNo - 1, sutunNo - 1)) {
        cout << "Gecersiz satir veya sutun numarasi! Devam etmek icin Enter'a basin...";
        cin.get();
    }
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
                if (seciliDugum != nullptr) matrisIslemMenusu();
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