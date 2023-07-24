#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 20

int pickNum(int numarr[MAXSIZE],int N,int Total,int k,int nowIndex,int chosenNum,int nowTotal)
{
    // printf("1\n");
    if (nowIndex == N){
        if (nowTotal <= Total && chosenNum >= k)
            return 1;
        else{
            return 0;
        }
    }
    
    return (pickNum(numarr,N,Total,k,nowIndex+1,chosenNum+1,nowTotal+numarr[nowIndex]) + pickNum(numarr,N,Total,k,nowIndex+1,chosenNum,nowTotal));
}

int main(void)
{
    int k,N,Total;
    scanf("%d%d%d",&k,&N,&Total);

    int numarr[MAXSIZE];
    for (int i = 0; i < N; i++){
        scanf("%d",&numarr[i]);
    }

    printf("%d",pickNum(numarr,N,Total,k,0,0,0));




    
    
    return 0;
}
