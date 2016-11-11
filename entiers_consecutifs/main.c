#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entier, limite, temp1=0, temp2;
    printf("Entrez un entier:\n");
    scanf("%d", &entier);
    printf("Entrez une limite:\n");
    scanf("%d", &limite);
    temp2=entier;
    do
    {
        temp1=temp1+temp2;
        printf("%d\n", temp2);
        temp2++;
    }
    while(temp1<=limite);
    return 0;
}
