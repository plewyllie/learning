#include <stdio.h>
#include <stdlib.h>

/**
 * Displays the number and increments it
 * @return Incremented integer
 */
int display_modify(int a);
int display_modify_ptr(int* a);

int main() {
    int a = 4;
    printf("%d \n", display_modify(a));
    printf("%d \n", display_modify(a));
    printf("%d \n", display_modify(a));

    printf("%d \n", display_modify_ptr(&a));
    printf("%d \n", display_modify_ptr(&a));
    printf("%d \n", display_modify_ptr(&a));
}

int display_modify(int a) {
//    printf("%d\n", a);
    a++;
    return a;
}
int display_modify_ptr(int* a) {
    (*a)++;
    return *a; // I return value, not pointer
}
