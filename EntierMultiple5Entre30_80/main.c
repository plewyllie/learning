#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entier;
    int resultat;
    scanf("%d", &entier);
    resultat = entier%5;
    if (entier<30 || entier>80)
    {
        printf("Faux\n");
    }
    else
    {
        if(resultat==0)
        {
            printf("Vrai\n");
        }
    }
    return 0;
}
