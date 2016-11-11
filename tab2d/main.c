#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[5][4];
    
    int i,j;
    for (i = 0; i < 5; i++) {
        printf("\n");
        for (j = 0; j < 4; j++) {
            tab[i][j] = 0;
            printf("%d", tab[i][j]);
        }
    }

    printf("\n");

}
