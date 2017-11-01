#include "pixel.h"
#include <iostream>

Pixel::Pixel() {
  std::cout << "Constructeur Pixel defaut" << std::endl;
}

Pixel::Pixel(int a, int b) : Forme::Forme(a ,b) {
  std::cout << "Constructeur Pixel a b" << std::endl;
}

void Pixel::print_un_truc() {
  std::cout << "Je suis un pixel!" << std::endl;
}
