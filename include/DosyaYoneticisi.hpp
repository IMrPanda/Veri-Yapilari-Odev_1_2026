/** 
* @file        DosyaYoneticisi.hpp
* @description DosyaYoneticisi sınıfının başlık dosyası.
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#ifndef DOSYAYONETICISI_HPP
#define DOSYAYONETICISI_HPP

#include <string>
#include "AnaListe.hpp"

class DosyaYoneticisi {
public:
    void dosyadanOku(const std::string& dosyaAdi, AnaListe* liste);
};

#endif