#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTRING 200000

int main(void)
{
    char FileName1[MAXSTRING],FileName2[MAXSTRING];
    scanf("%s %s",FileName1,FileName2);

    FILE *fp;
    fp = fopen(FileName1,"r");
    assert(fp != NULL);

    FILE *fp2;
    fp2 = fopen(FileName2,"r");
    assert(fp != NULL);

    char str1[MAXSTRING],str2[MAXSTRING];
    
    int line = 0;
    while (1) {
        fgets(str1,MAXSTRING,fp);
        fgets(str2,MAXSTRING,fp2);
        line++;
        if (strcmp(str1,str2)){
            break;
        }
    }
    printf("line:%d\n",line);
    
    return 0;
}
