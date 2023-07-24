#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 16
int main(void)
{
    char str[MAXSTR];
    scanf("%s",str);

    FILE *fp = fopen(str,"rb");
    assert(fp != NULL);

    int a;
    while (!feof(fp)){
        fread(&a,sizeof(int),1,fp);
        printf("%d ",a);
    }



   
    
    return 0;
}
