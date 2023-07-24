#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXARR 15

int count(int sum,int k,int index,int numarr[],int n)
{
    if (sum == k){
        // printf("sum:%d\n",sum);
        return 1;
    }
    if (index == n || sum > k){
        // printf("sum:%d\n",sum);
        return 0;
    }
    return (count(sum,k,index+1,numarr,n) + count(sum+numarr[index],k,index+1,numarr,n));
}

int main(void)
{
    int n;
    scanf("%d",&n);

    int numarr[MAXARR];
    for (int i = 0; i < n; i++){
        scanf("%d",&numarr[i]);
    }

    int k;
    while(scanf("%d",&k) != EOF){
        printf("%d\n",count(0,k,0,numarr,n));
    }


    
    
    return 0;
}
