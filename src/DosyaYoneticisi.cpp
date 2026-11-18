/** 
* @file        DosyaYoneticisi.cpp
* @description DosyaYoneticisi sınıfının implementasyon dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "DosyaYoneticisi.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void DosyaYoneticisi::dosyadanOku(const string& dosyaAdi, AnaListe* liste) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) { 
        cout << "Hata: " << dosyaAdi << " dosyasi acilamadi!" << endl; // dosya açılamadıysa hata mesajı ver
        return;
    }

    int sutun, satir;
    int sayi;
    string satirStr;

    while (getline(dosya, satirStr)) { // satır

        if (satirStr.empty()) continue; // boş satırsa geç

        istringstream ss(satirStr); 
        if (!(ss >> sutun >> satir)) continue; // sütun ve satır sayısını oku, bitince geç

        Matris* matris = new Matris(sutun, satir); 
        while (ss >> sayi) { 					// matrisin elemanlarını oku
            matris->sonaEkle(sayi);
        }

        if (!matris->MatrisBosMu()) {			// matris boş değilse listeye artOrta göre ekle
            liste->ortGoreEkle(matris);

        } else {								// matris boşsa sil
            delete matris;
        }

    }

    dosya.close();
}

		
	
	

	
	
	