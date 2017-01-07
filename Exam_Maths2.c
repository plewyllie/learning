#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG

void afficher_matrice(int l, int c, double matrice[l][c])
{
    int i, j;
    for(i = 0; i < l; i++)
    {
        printf("\n");
        for(j = 0; j < c; j++)
        {
            printf("%f\t", matrice[i][j]);
        }
        printf("\n");
    }
}

/**
 * @return determinant de la matrice 3x3
 */
int calcul_determinant(double matrice[3][3])
{
    int i, j, k;
    int determinant = 1;
    int temp1, temp2;
    //Calcul du determinant via Gauss
    //partie1
    for(k = 0; k < 3; k++)
    {
        temp1 = 1;
        for(i = 0, j = k; i < 3; i++, j = (j + 1) % 3)
        {
            temp1 *= matrice[i][j];
        }
        determinant += temp1;

        temp2 = 1;

        /*for(i = 0, j = k; i<3; i++, j = (j-1)%3)
        {
            temp2 *= matrice[i][j];
            printf("Matrice 2 = %d\n", matrice[i][j]);
            printf("Test %d = %d\n", i, temp2);
        }*/
        //Probleme avec le modulo en C ca laisse la valeur en negatif ! ! ! ! !

        // Partie 2
        for(i = 0, j = k; i < 3; i++, j--)
        {
            if(j >= 0)
            {
                temp2 *= matrice[i][j];
            }
            else
            {
                j = 2;
                temp2 *= matrice[i][j];
            }
        }
        determinant -= temp2;
    }
    return determinant;
}

/**
 * @return le pivot sur la col colonne de la matrice[3][3] à partir de ligne ligne
 * int* LignePivot est modifié avec la valeur de la nouvelle LignePivot
 */
double recherche_pivot(int col, int ligne, double matrice[3][3], int* LignePivot)
{
    int i;
    double pivot = fabs(matrice[ligne][col]);
    *LignePivot = ligne;
    for(i = ligne + 1;i<3;i++)
    {
        if(fabs(matrice[i][col])>pivot)
        {
            pivot = fabs(matrice[i][col]);
            *LignePivot = i;
        }
    }
    return pivot;
}

/**
 * permute la ligne pivot avec ligne de matrice[l][c]
 */
void permutation_lignepivot(int LignePivot, int ligne,
                            int l, int c, double matrice[l][c])
{
    double temp1;
    int j;
    if (LignePivot != ligne) {
        if (LignePivot !=  0)
        {
            for(j = 0; j < c; j++)
            {
                temp1 = matrice[ligne][j];
                matrice[ligne][j] = matrice[LignePivot][j];
                matrice[LignePivot][j] = temp1;
            }
        }
    }
}

int main()
{
    int i, j, k, LignePivot, temp1, temp2, determinant;
    double matrice [3][3], coefficient = 0, x, y, z, tempF;
    double matriceR[3][1];
    double pivot;

#ifndef DEBUG
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("Entrez la valeur de la case N %d de la ligne %d : \n", j, i);
            scanf("%f", &matrice[i][j]);
        }
    }
#else
    matrice[0][0] = 2;
    matrice[0][1] = 4;
    matrice[0][2] = 4;
    matrice[1][0] = 3;
    matrice[1][1] = 2;
    matrice[1][2] = 1;
    matrice[2][0] = 4;
    matrice[2][1] = 5;
    matrice[2][2] = 6;

    matriceR[0][0] = 1;
    matriceR[1][0] = 9;
    matriceR[2][0] = 8;
#endif
    // Affichage de la matrice entree
    printf("Matrice entree : \n");
    afficher_matrice(3, 3, matrice);
    printf("Matrice resultats : \n");
    afficher_matrice(3, 1, matriceR);

    determinant = calcul_determinant(matrice);
    printf("Le determinant de la matrice est : %d\n", determinant);

    pivot = recherche_pivot(0, 0, matrice, &LignePivot);
    if (pivot == 0)
    {
        printf("Le pivot vaut 0, systeme impossible !\n");
        return 1;
    }

    //Permutation des lignes LignePivot et de la ligne 0
    permutation_lignepivot(LignePivot, 0, 3, 3, matrice);
    permutation_lignepivot(LignePivot, 0, 3, 1, matriceR);

    printf("Matrice entree : \n");
    afficher_matrice(3, 3, matrice);
    printf("Matrice resultats : \n");
    afficher_matrice(3, 1, matriceR);
    printf("Pivot %f\n", pivot);
    printf("Ligne Pivot %d\n", LignePivot);

    // Supression des x sur L2 et L3
    for (i = 1; i < 3; i++)
    {
        coefficient = matrice[i][0]/matrice[0][0];
        for(j = 0; j < 3; j++)
        {
            matrice[i][j] = matrice[i][j] - (coefficient*matrice[0][j]);
        }
        matriceR[i][0] = matriceR[i][0]-(coefficient*matriceR[0][0]);
    }

    pivot = recherche_pivot(1, 1, matrice, &LignePivot);
    if (pivot == 0)
    {
        printf("Le pivot vaut 0, systeme impossible !\n");
        return 1;
    }

    //Permutation des lignes LignePivot et de la ligne 1
    permutation_lignepivot(LignePivot, 1, 3, 3, matrice);
    permutation_lignepivot(LignePivot, 1, 3, 1, matriceR);

    //Supression des y sur L3
    for(i = 2; i < 3; i++)
    {
        coefficient = matrice[i][1]/matrice[1][1];
        printf("coefficient : %f\n", coefficient);
        for(j = 1; j<3; j++)
        {
            matrice[i][j] = matrice[i][j] - (coefficient*matrice[1][j]);
        }
        matriceR[i][0] = matriceR[i][0]-(coefficient*matriceR[1][0]);
    }

    /* Calcul des resultats x, y, z */
    // z
    z = matriceR[2][0]/matrice[2][2];

    // y
    tempF = matrice[1][2];
    tempF *= z;
    matriceR[1][0] -= tempF;
    y = matriceR[1][0]/matrice[1][1];

    // x
    tempF = matrice[0][2];
    tempF *= z;
    matriceR[0][0] -= tempF;
    tempF = matrice[0][1];
    tempF *= y;
    matriceR[0][0] -= tempF;
    x = matriceR[0][0]/matrice[0][0];

    printf("x = %f\n", x);
    printf("y = %f\n", y);
    printf("z = %f\n", z);
}
