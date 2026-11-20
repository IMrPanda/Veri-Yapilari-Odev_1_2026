#include "Uygulama.hpp"

int main() {
    Uygulama* app = new Uygulama("kayitlar.txt");
    app->calistir();
    delete app;
    return 0;
}