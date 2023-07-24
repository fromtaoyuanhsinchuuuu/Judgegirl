#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Doll {
    char top, bottom;
    struct Doll *interior;
} Doll;
 
Doll *newDoll(char top, char bottom)
{
    Doll *doll = (Doll *) malloc(sizeof(Doll));
    doll->top = top;
    doll->bottom = bottom;

    return doll;
}
void package(Doll *outer, Doll *inter)
{
    outer->interior = inter;
}
const char* doll_c_str(Doll *doll)
{
    if (doll == NULL){
        return "dick\n";
    }

    printf("%c",doll->top);
    doll_c_str(doll->interior);
    printf("%c",doll->bottom);
    return "dick\n";
}

int main(void)
{
    Doll *dolls[3];
    dolls[0] = newDoll('<', '~');
    dolls[1] = newDoll('(', ')');
    dolls[2] = newDoll('@', '>');
    package(dolls[1], dolls[2]);
    package(dolls[0], dolls[1]);
    printf("%s\n", doll_c_str(dolls[0]));
    return 0;
}

   
    