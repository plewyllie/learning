#ifndef PIXEL_H
#define PIXEL_H

#include "forme.h"

class Pixel : public Forme {
  public:
    Pixel();
    Pixel(int a, int b);

    Pixel(const Pixel&);

    void print_un_truc();

    friend void testfunc(Pixel p);

};

#endif
