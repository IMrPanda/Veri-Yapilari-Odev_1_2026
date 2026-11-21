/** 
* @file        main.cpp
* @description uygulama dosyasını çalıştıran ve exe oluşturan main fonksiyonu olan sınıf
* @course      1. Öğretim A Grubu 
* @assignment  1. Ödev
* @date        18.11.2026
* @author      Sinan Ulusinan - sinan.ulusinan@ogr.sakarya.edu.tr
*/

#include "Uygulama.hpp"

int main() {
    Uygulama* app = new Uygulama("kayitlar.txt");
    app->calistir();
    delete app;
    return 0;
}