#include <iostream>
#include <locale.h>
#include "controllers/AppController.hpp"

int main() {
    setlocale(LC_ALL, "");
    AppController app;

    app.run();

    return 0;
}