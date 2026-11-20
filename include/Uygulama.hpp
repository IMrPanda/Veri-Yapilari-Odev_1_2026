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
	void yukariGit();
	void asagiGit();


public:
	Uygulama(const string& dosyaAdi); // kurucu
	~Uygulama(); // yıkıcı

	void calistir();
};

#endif