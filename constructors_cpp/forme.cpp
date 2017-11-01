#include "forme.h"
#include <stdio.h>
#include <iostream>

Forme::Forme() {
  std::cout << "Constructeur Forme defaut" << std::endl;
  a = 0;
  b = 0;
}

Forme::Forme(int a, int b) {
  std::cout << "Constructeur Forme a b" << std::endl;
  this->a = a;
  this->b = b;
}

void Forme::print_value_a() {
  std::cout << a << std::endl;
}

void Forme::print_un_truc() {
  std::cout << "Je suis une forme!" << std::endl;
}
