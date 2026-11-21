/** 
* @file        Uygulama.hpp
* @description Konsol uygulamasının başlık dosyası. AnaListe ve DosyaYoneticisi sınıflarını kullanarak matrisleri yönetir.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        20.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#ifndef UYGULAMA_HPP
#define UYGULAMA_HPP

#include <string>
#include "AnaListe.hpp"
#include "DosyaYoneticisi.hpp"
using namespace std;

class Uygulama {
private:
	AnaListe* liste;
	DosyaYoneticisi* dosyaYoneticisi;
	string dosyaAdi;
	ListeDugum* seciliDugum;
	int seciliIndex;

	void anaEkraniGoster() const;
	void eklendiEkrani(ListeDugum* yeniDugum) const;
	void yukariGit();
	void asagiGit();

	// ----------------------------------------------
	// matris ekleme
	Matris* rastgMatrisUret() const;
	void onMatrisEkle();
	void arkaMatrisEkle();

	// matris silme
	void matrisIslemMenusu();
	bool satirSil();
	bool sutunSil();
	void satirSutunDegistir();


public:
	Uygulama(const string& dosyaAdi); // kurucu
	~Uygulama(); // yıkıcı

	void calistir();
};

#endif