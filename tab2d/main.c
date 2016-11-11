#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[5][4];
    
    int i,j;
    for (i = 0; i < 5; i++) {
        printf("\n");
        for (j = 0; j < 4; j++) {
            if(i==2){
            tab[i][j] = 1;
            printf("%d", tab[i][j]);
            }
            else
            {
            tab[i][j] = 0;
            printf("%d", tab[i][j]);
            }
        }
    }

    printf("\n");

}
