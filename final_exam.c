#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int matrice [3][3], i, j, k, temp1, temp2, determinant=0, LignePivot, pivot=0, coefficient=0;

#if 0
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Entrez la valeur de la case N %d de la ligne %d : \n", j, i);
            scanf("%d", &matrice[i][j]);
        }
    }
#endif

    matrice[0][0] = 2;
    matrice[0][1] = 1;
    matrice[0][2] = 3;
    matrice[1][0] = -2;
    matrice[1][1] = 0;
    matrice[1][2] = -3;
    matrice[2][0] = 5;
    matrice[2][1] = 2;
    matrice[2][2] = 6;

    //Affichage de la matrice entree
    printf("Matrice entree : \n");

    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<3; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
    //Calcul duy determinant via Gauss
    //partie1
    for(k=0; k<3; k++)
    {
        temp1=1;
        for(i=0, j=k; i<3; i++, j=(j+1)%3)
        {
            temp1*=matrice[i][j];
        }
        determinant+=temp1;

        temp2=1;

        /*for(i=0, j=k; i<3; i++, j=(j-1)%3)
        {
            temp2*=matrice[i][j];
            printf("Matrice 2 = %d\n", matrice[i][j]);
            printf("Test %d = %d\n", i, temp2);
        }*/
        //Probleme avec le modulo en C ca laisse la valeur en negatif ! ! ! ! !

        //Partie 2
        for(i=0, j=k; i<3; i++, j--)
        {
            if(j>=0)
            {
                temp2*=matrice[i][j];
            }
            else
            {
                j=2;
                temp2*=matrice[i][j];
            }
        }
        determinant-=temp2;
    }
    printf("Le determinant de la matrice est : %d\n", determinant);

    //Calcul du x, y et z

    //Recherche de la ligne Pivot sur la 1iere colonne
    LignePivot=0;
    pivot = abs(matrice[0][0]);
    for(i=1;i<3;i++)
    {
        if( abs(matrice[i][0])>pivot)
        {
            pivot = abs(matrice[i][0]);
            LignePivot = i;
        }
    }
    if(matrice[LignePivot][0] == 0)
    {
        printf("Le pivot vaut 0 !\n");
        return 1;
    }

#if 0
    printf("Pivot %d\n", pivot);
    printf("Ligne Pivot %d\n", LignePivot);
#endif

    //Permutation des lignes LignePivot et de la ligne 0
    if ( LignePivot !=0)
    {
        for(j=0; j<3; j++)
        {
            temp1 = matrice[0][j];
            matrice[0][j] = matrice[LignePivot][j];
            matrice[LignePivot][j] = temp1;
        }
    }
    //Supression des x sur L2 et L3
    for(i=1; i<3; i++)
    {
        coefficient = matrice[i][0]/matrice[0][0];
        for(j=0; j<3; j++)
        {
            matrice[i][j] = matrice[i][j] - (coefficient*matrice[0][j]);
        }
    }

#if 0 // affichage matrice
    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<3; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
#endif

    //Recherche de la ligne Pivot sur la 2ieme colonne
    LignePivot=1;
    pivot = abs(matrice[1][1]);
    for(i=2;i<3;i++)
    {
        if( abs(matrice[i][1])>pivot)
        {
            pivot = abs(matrice[i][1]);
            LignePivot = i;
        }
    }
    if(matrice[LignePivot][1] == 0)
    {
        printf("Le pivot vaut 0 !\n");
        return 1;
    }
    #if 1
        printf("Pivot %d\n", pivot);
        printf("Ligne Pivot %d\n", LignePivot);
    #endif

    //Permutation des lignes LignePivot et de la ligne 2
    if ( LignePivot !=0 && (matrice[1][j]>matrice[LignePivot][j]))
    {
        for(j=1; j<3; j++)
        {
            temp1 = matrice[1][j];
            matrice[1][j] = matrice[LignePivot][j];
            matrice[LignePivot][j] = temp1;
        }
    }

    //Supression des y sur L3
    for(i=2; i<3; i++)
    {
        coefficient = matrice[i][1]/matrice[1][1];
        for(j=1; j<3; j++)
        {
            matrice[i][j] = matrice[i][j] - (coefficient*matrice[1][j]);
        }

    }
    for(i=1; i<3; i++)
    {
        coefficient = matrice[i][0]/matrice[0][0];
        for(j=0; j<3; j++)
        {
            matrice[i][j] = matrice[i][j] - (coefficient*matrice[0][j]);
        }

    }
    for(i=2; i<3; i++)
    {
        coefficient = matrice[i][1]/matrice[1][1];
        for(j=1; j<3; j++)
        {
            matrice[i][j] = matrice[i][j] - (coefficient*matrice[1][j]);
        }

    }
    printf("Matrice Apres : \n");

    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<3; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}
