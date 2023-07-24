#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    int num;
    int total = 0;

    while (scanf("%d",&num) != EOF){
        total += num;
    }
    printf("%d\n",total);

    
    
    return 0;
}
