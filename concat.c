#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* putting three strings ending by \0 in single array */

int main()
{
    char Nom[20]={0}, Prenom[20]={0}, NomPrenom[40]={0};

    int taille, taille2;
    printf("Entrez votre nom : ");
    gets(Nom);
    printf("\nEntrez votre prenom : ");
    gets (Prenom);

    /* ------- */

    strcpy(NomPrenom, Nom);
    
    taille=strlen(NomPrenom);
    strcpy(&NomPrenom[taille + 1], " ");
    
    taille2=strlen(&NomPrenom[taille + 1]);
    strcpy(&NomPrenom[taille + taille2 + 2], Prenom);


    puts(NomPrenom);
    puts(&NomPrenom[taille + 1]);
    puts(&NomPrenom[taille + taille2 + 2]);

    return 0;
}