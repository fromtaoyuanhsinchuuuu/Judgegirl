#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXCH 40
#define MAXN 65

int cmp(const void *a, const void *b)
{
    char **ptr1 = (char **)a;
    char **ptr2 = (char **)b;

    return (strcmp(*ptr1,*ptr2));
}

int main(void)
{
    char line_arr[MAXN][MAXCH];
    char *ptr_arr[MAXN];
    int n = 0;

    while (fgets(line_arr[n],MAXCH,stdin) != NULL){
        ptr_arr[n] = line_arr[n];
        n++;
    }

    qsort(ptr_arr,n,sizeof(char*),cmp);
    for (int i = 0; i < n; i++){
        printf("%s",ptr_arr[i]);
    }
    
    return 0;
}
