#include "forme.h"
#include "pixel.h"

void print_une_forme(Forme* f) {
  f->print_un_truc();
}

int main() {

  Forme origin;
  Forme copied(origin);

  Pixel originp;
  Pixel copiedp(originp);

  /* constructeurs */
  Forme* f = new Forme;
  f->print_value_a();

  Pixel* p = new Pixel;
  p->print_value_a();

  Forme* f1 = new Forme(1, 2);
  f1->print_value_a(); // output 1

  Pixel* p1 = new Pixel(1, 2);
  p1->print_value_a(); // output 1


  /* test virtual */
  f->print_un_truc();
  p->print_un_truc();

  print_une_forme(f);
  print_une_forme(p);

  return 0;
}
