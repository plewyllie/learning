#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
//Version avec fonction
void verification(int [], int);

int main()
{
    int v[7], i;
    srand(time(NULL));
 
    for(i=0; i<7; i++)
    {
        v[i]=rand()%42;
        verification(v, i);
    }
 
    for(i=0; i<7; i++)
    {
        printf("%d\t", v[i]);
    }
    return 0;
}
 
void verification(int v[7], int i)
{
    int j = 0;

    while ((v[i] == v[j] && j < i) || v[i] == 0) {
        v[i] = rand()%42;
        j++;
    }
}