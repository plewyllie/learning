#include <stdio.h>
#include <stdlib.h>
 
int LireVCar(char * c, int t);
void AfficherVCar(char *c, int t);
 
int main()
{
    int t, nbr;
    char *c, vecteur[20];
    printf("Entrez la taille maximale du vecteur de caracteres : \n");
    scanf("%d", &t);
    getchar();
    t = 5;
    c=vecteur;
    nbr=LireVCar(c, t);
    AfficherVCar(c, t);
}
 
int LireVCar(char * c, int t)
{
    int i;
    // fflush (stdin); // THIS IS UNDEFINED BEHAVIOR, depends on the OS
    // http://stackoverflow.com/questions/16752759/fflush-doesnt-work
    for(i=0; i<t; i++)
    {
        printf("Entrez le caractere %d de la chaine\n", i);
        *(c+i)=getchar();
        //fflush (stdin);
        getchar();
    }
    return 0;
}
void AfficherVCar(char *c, int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        printf("%c", *(c+i));
    }

    // OR printf("%s", c);

    printf("\n");
}