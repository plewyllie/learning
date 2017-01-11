#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("test%*s\n", 13, "test");
    printf("test%*s\n", 13, "longer test");
    printf("test%*s\n", 13, "even longer longer test");
    printf("test%.*s\n", 5, "even longer test");
    printf("test %*c\n", 13, 't');
}
