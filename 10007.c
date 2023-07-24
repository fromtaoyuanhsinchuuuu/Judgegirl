#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1000

int main(void)
{
    int n;
    int arr[MAXN];
    while (scanf("%d",&n) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%d",arr + i);
        }
        int prev = arr[0];
        int seg = 1;
        for (int i = 1; i < n; i++){
            if (arr[i] != prev){
                seg++;
            }
            prev = arr[i];
        }
        printf("%d",seg);


    }
    
    
    return 0;
}
