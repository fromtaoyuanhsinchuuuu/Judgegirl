#include <stdio.h>

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int m[7];
    for (int i = 6 ; i >= 0 ; i--){
        m[i] = M%10;
        M /= 10;
    }
    int count = 0;
    for (int i = 0 ; i <= 5 ; i++){
        if (m[i]*10 + m[i+1] == N){
            count += 1;
        }
    }
    printf("%d",count);
    return 0;
}
