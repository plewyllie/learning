#include <stdio.h>
#include <stdlib.h>

int main()
{
    int enfants;
    float achats;
    printf("Entrez la somme à payer\n");
    scanf("%f", &achats);
    if (achats>25)
    {
        achats=(achats/10)*9;
        printf("Le montant à payer est de %f", achats);
    }
    else
    {
        if (achats<=25)
        {
        printf ("Entrez le nombre d'enfants\n");
        scanf("%d", &enfants);
            if (enfants>=3)
            {
                achats=(achats/10)*9;
                printf("Le montant à payer est de %f", achats);
            }
            else
            {
                achats=(achats/20)*19;
                printf("Le montant à payer est de %f", achats);
            }
        }   
    }
}
