#include <stdio.h>

int main(void)
{
    int N,m;
    scanf("%d%d",&N,&m);
    int sum[1000]={0};
    int min[1000];
    int max[1000];
    for (int i = 0 ; i < 1000 ; i++){
        min[i] = -1;
        max[i] = -1;
    }
    for (int i = 0 ; i < N ; i++){
        int x;
        scanf("%d",&x);
        int remainder = x % m;
        sum[remainder] += x;
        if (x <= min[remainder] || min[remainder] == -1){
            min[remainder] = x;
        }
        if (x >= max[remainder] || max[remainder] == -1){
            max[remainder] = x;
        }
    }
    for (int i = 0 ; i < m ; i++){
        printf("%d %d %d\n",sum[i],max[i],min[i]);
    }
    return 0;
}
