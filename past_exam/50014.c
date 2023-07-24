#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

bool choose(int numbers[],int n, int K, int S, int now_sum, int nowK,int now_index)
{
    if (nowK == S && now_sum == K){
        return 1;
    }
    if (now_index == n){
        return 0;
    }
    if (now_sum > K || nowK > S){
        return 0;
    }
    if (choose(numbers,n,K,S,now_sum + numbers[now_index],nowK + 1,now_index+1)
        || choose(numbers,n,K,S,now_sum,nowK,now_index+1)){
        return 1;
    }
    return 0;
}

int subset(int numbers[], int n, int K, int S)
{
    return choose(numbers,n,K,S,0,0,0);

}

int main() {
    int n, K, S;
    while (scanf("%d %d %d", &n, &K, &S) == 3) {
        int A[128];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", subset(A, n, K, S));
    }
    return 0;
}
