#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100000

int cmp(const void *a,const void *b)
{
    int *ptr1 = (int *)a;
    int *ptr2 = (int *)b;

    if (*ptr1 != 0 && *ptr2 != 0){
        return 0;
    }
    if (*ptr1 == 0){
        return 1;
    }
    assert(*ptr2 == 0);
    return -1;
}

int main(void)
{
    int n;

    scanf("%d",&n);
    int ARR[MAXN];
    for (int i = 0; i < n; i++){
        scanf("%d",&ARR[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++){
        if (ARR[i]){
            printf("%d ",ARR[i]);
            count++;
        }

    }

    for (int i = 0; i < n - count; i++){
        printf("%d%c",0," \n"[i == n - count - 1]);
    }

    


    
    
    return 0;
}
