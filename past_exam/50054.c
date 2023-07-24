#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLEN 101
#define MAXN 10000
#define MAXS 10000

int f(int S,char *str)
{
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (!isdigit(str[i])){
            sum += str[i];
        }
        else{
            sum += str[i] - '0';
        }
    }
    return sum % S;
}

int main(void)
{
    int S,N,Q;
    scanf("%d%d%d",&S,&N,&Q);

    char str[MAXLEN];
    static char hash_table[MAXN][MAXS][MAXLEN];
    int hash_index_arr[MAXN] = {};
    for (int i = 0; i < N; i++){
        scanf("%s",str);
        int hash_index = f(S,str);
        strcpy(hash_table[hash_index][hash_index_arr[hash_index]],str);
        hash_index_arr[hash_index]++;
    }

    for (int i = 0; i < Q; i++){
        scanf("%s",str);
        int hash_index = f(S,str);

        bool find = 0;
        for (int j = 0; j < hash_index_arr[hash_index]; j++){
            if (!strcmp(str,hash_table[hash_index][j])){
                printf("%d\n",hash_index);
                find = 1;
                break;
            }
        }

        if (!find){
            printf("-1\n");
        }



    }

    
    
    return 0;
}
