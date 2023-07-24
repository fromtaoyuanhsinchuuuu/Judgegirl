#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef long long ll;

bool CanReach(int target,int maxA,int maxB,int maxC,int a,int b,int c,int numA,int numB,int numC)
{
    if (maxA * (ll)a + maxB * (ll)b + maxC * (ll)c == target){
        return 1;
    }
    else if (maxA * (ll)a + maxB * (ll)b + maxC * (ll)c < target){
        return 0;
    }

    ll sum = numA * (ll)a + numB * (ll)b + numC * (ll)c;

    if (numA > maxA || numB > maxB || numC > maxC || sum > target){
        return 0;
    }
    else if (sum == target){
        return 1;
    }
    if (CanReach(target,maxA,maxB,maxC,a,b,c,numA+1,numB,numC) || CanReach(target,maxA,maxB,maxC,a,b,c,numA,numB+1,numC) || CanReach(target,maxA,maxB,maxC,a,b,c,numA,numB,numC+1)){
        return 1;
    }
    return 0;

}

int main(void)
{
    int N;
    scanf("%d",&N);

    int target,maxA,maxB,maxC,a,b,c;
    for (int i = 0; i < N; i++){
        scanf("%d%d%d%d%d%d%d",&target,&maxA,&maxB,&maxC,&a,&b,&c);
        if (CanReach(target,maxA,maxB,maxC,a,b,c,0,0,0)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }



    
    
    return 0;
}
