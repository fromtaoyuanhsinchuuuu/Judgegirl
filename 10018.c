#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1000000

int main(void)
{
    int arr[MAXN] = {};

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        int num;
        scanf("%d",&num);

        if (arr[num - 1] == 1){
            printf("%d\n",num);
            // exit(1);
        }
        arr[num - 1]++;
    }

    
    
    return 0;
}
