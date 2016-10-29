#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int a, b, c;
    int rho;
    float x1, x2;

    printf("Entrez a b c\n");
    scanf("%d %d %d", &a, &b, &c);
    
    if (b == 0 && c == 0) {
        printf("Indetermine!\n");
    } else {
        if (b == 0 && c != 0) {
            printf("Impossible!\n");
        } else {
            rho = b*b - 4*a*c;
            if (rho >= 0) {
                x1 = (-b + sqrt(rho))/2*a;
                x2 = (-b - sqrt(rho))/2*a;
                printf("Resultats x1 %f x2 %f\n", x1, x2);
            } else {
                printf("Impossible!\n");
            }
        }
    }
    return 0;
}

