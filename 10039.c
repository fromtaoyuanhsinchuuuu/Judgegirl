#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 100001
#define MAXN 100000

int main(void)
{
    char str[MAXSTR];
    scanf("%s",str);

    int N;
    scanf("%d",&N);

    int len = strlen(str);
    for (int i = 0; i < N; i++){
        char ch1,ch2;
        scanf(" %c %c",&ch1,&ch2);

        for (int i = 0; i < len; i++){
            if (str[i] == ch2){
                str[i] = ch1;
            }
        }
    }

    printf("%s",str);

   
    
    return 0;
}
