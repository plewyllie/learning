#ifndef FORME_H
#define FORME_H

class Forme {
  protected:
    int a;
    int b;

  public:
    Forme();
    Forme(int a, int b);

    Forme(const Forme &f);

    void print_value_a();
    void print_value_b();

    virtual void print_un_truc();
};

#endif
