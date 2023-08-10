#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 2005
#define MAXSTR 55

int main(void)
{
    int N, M;
    scanf("%d%d", &N, &M);
    char str[MAXN];

    for (int i = 0; i < N; i++){
        str[i] = '\0';
    }

    char tmp_str[MAXSTR];

    int len = -1, idx = 0;
    while (M--){
        scanf("%s%d", tmp_str, &idx);
        len = strlen(tmp_str);
        for (int i = 0; i < len; i++){
            if (str[i + idx] == '\0') str[idx + i] = tmp_str[i];
            if (str[i + idx] != '\0') str[idx + i] = (str[idx + i] + tmp_str[i]) / 2;
        }
    }

    for (int i = 0; i < N; i++){
        if (str[i] == '\0') printf(" ");
        else printf("%c", str[i]);
    }

    
    return 0;
}
