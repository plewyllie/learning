#include <stdio.h>
#include <stdlib.h>

int main() {
    /* on utilise le heap */
    int a; // entier, sur le "heap (tas)"
    a = 3;
    printf("Addresse de a %d\n", &a); // &a est le pointeur vers a
    int* c = &a;
    *c = 4; // c pointe vers a et donc on va remplacer la valeur de a par 4
    printf("a = %d\n", a);
    printf("sizeof(int): %d \n", sizeof(int));
    printf("malloc(sizeof(int)): %d \n", malloc(sizeof(int)));

    /* on utilise le "stack" */
    int* b = malloc(sizeof(int));
    *b = 3;
    free(b);
    printf("%d %d\n", a, *b); // affiche la valeur
    printf("%d %d\n", &a, b); // affiche l'addresse
    
    /* tableau sur le heap */
    int t[30];
    // init du tableau
    /* goal: t[0] = 0; t[1] = 0; t[2] = 0;... t[29] = 0
     * on déclare donc un entier (par exemple i) qu'on incrémente 30x
     * t[i] = 0
     */
    int v;
    for (v = 0; v<30; v++) {
        t[v]=0;
    }
    // print t
    int i = 0;
    for (i = 0; i < 30; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
    // print t using pointer logic
    int* k = t; 
    for (i = 0; i < 30; i++) {
        printf("%d ", *(k + i));
    }
    printf("\n");
    
    // even easier
    for (i = 0; i < 30; i++) {
        printf("%d ", *(t + i));
    }
    printf("\n");

    // put every value of our table to 1
    int p;
    int* j = t;
    for (p = 0; p < 30; p++){
        *(j+p)=1;

        printf("%d", j[p]); 
        
    }

}
