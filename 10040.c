#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 100
#define MAXN 200
#define MAXQ 50

int main(void)
{
    int N;
    scanf("%d",&N);

    char dict[MAXN][MAXSTR];
    for (int i = 0; i < N; i++){
        scanf("%s",dict[i]);
    }

    int Q;
    scanf("%d",&Q);

    char str[MAXSTR];
    for (int i = 0; i < Q; i++){
        scanf("%s",str);

        int count = 0;
        for (int j = 0; j < N; j++){
            if (strstr(dict[j],str) != NULL){
                count++;
            }
        }
        printf("%d\n",count);
    }


    

   
    
    return 0;
}
