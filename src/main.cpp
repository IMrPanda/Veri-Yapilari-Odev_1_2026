#include <iostream>
#include "Matris.hpp"

using namespace std;

int main() {
    Matris* m = new Matris(3, 2); // 3 sütun, 2 satır   // kontrol testi
    for (int i = 1; i <= 6; i++) {
        m->sonaEkle(i * 10);
    }

    m->yazdir();
    cout << "Ortalama: " << m->artOrt() << endl;

    delete m;
    return 0;
}