#include <iostream>
#include "AnaListe.hpp"
#include "DosyaYoneticisi.hpp"

using namespace std;   // test 

int main() {
    AnaListe* liste = new AnaListe();
    DosyaYoneticisi* dosya = new DosyaYoneticisi();

    dosya->dosyadanOku("kayitlar.txt", liste);
    cout << "Toplam okunan matris: " << liste->getDugumSayisi() << endl;
    liste->ozetYazdir();

    delete dosya;
    delete liste;
    return 0;
}