#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 3; // 32 bits = 4 bytes

    char cc = 'c'; // 8 bits = 1 byte

    char b[6] = {'S', 'a', 'l', 'u', 't', 0};
    char* c = "Salut";

    printf("%s \n", b); 
}

