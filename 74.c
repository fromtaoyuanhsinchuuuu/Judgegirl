#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int x[n];
    for (int i = 0 ; i < n ; i++){
        int k;
        scanf("%d",&k);
        x[i] = k;
    }
    int div;
    scanf("%d",&div);
    int ans[200000] = {0};
    for (int i = 0 ; i < n ; i++){
        ans[x[i]%div] += 1;
    }
    // printf("\n");
    for (int i = 0 ; i < div ; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}