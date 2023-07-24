#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 50
#define STRINGLEN 10

int main(void)
{
    int n,r,w;
    char Ans_arr[MAXN][STRINGLEN];

    int m;
    char cmp_arr[MAXN][STRINGLEN];
    char ans[STRINGLEN];

    while (scanf("%d%d%d",&n,&r,&w) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%s",Ans_arr[i]);
        }
        scanf("%d",&m);
        for (int i = 0; i < m; i++){
            int score = 0;
            for (int j = 0; j < n; j++){
                scanf("%s",ans);
                if (!strcmp(ans,"N/A")){
                    continue;
                }
                int len = strlen(ans);
                for (int k = 0; k < len; k++){
                    ans[k] = toupper(ans[k]);
                }
                for (int k = 0; k < len; k++){
                    for (int l = 0; l < len - 1; l++){
                        if (ans[l] > ans[l + 1]){
                            char c = ans[l];
                            ans[l] = ans[l + 1];
                            ans[l + 1] = c;
                        }
                    }
                }
                if (!strcmp(Ans_arr[j],ans)){
                    score += r;
                }
                else{
                    score -= w;
                }
            }
            printf("%d\n",(score >= 0)? score: 0);
        }
    }
    return 0;
}
