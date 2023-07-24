#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 1000

double exp(char *str)
{
    char *ptr;
    double p = strtod(str,&ptr);
    if (ptr == str + strlen(str)){
        return p;
    }

    


}

int main(void)
{
    char str[MAXSTR];
    scanf("%s",str);
    
    
    return 0;
}
