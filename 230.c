#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ARRSIZE 20

#define WEIGHT 0
#define VALUE 1

int better(int a,int b)
{
    return (a >= b)? a : b; 
}

int MaxValueFunc(int nowIndex,int weight_and_value[ARRSIZE][2],int nowValue,int nowWeight,int MaxWeight,int n)
{
    if (nowWeight > MaxWeight){
        nowValue -= weight_and_value[nowIndex - 1][VALUE];
        nowWeight -= weight_and_value[nowIndex - 1][WEIGHT];
    }
    if (nowIndex == n || nowWeight == MaxWeight){
        return nowValue;
    }

    return (better(MaxValueFunc(nowIndex+1,weight_and_value,nowValue + weight_and_value[nowIndex][VALUE],nowWeight + weight_and_value[nowIndex][WEIGHT],MaxWeight,n),
                    MaxValueFunc(nowIndex+1,weight_and_value,nowValue,nowWeight,MaxWeight,n)));

}





int main(void)
{
    int weight_and_value[ARRSIZE][2];

    int n,MaxWeight;
    scanf("%d%d",&n,&MaxWeight);

    for (int i = 0; i < n; i++){
        scanf("%d%d",&weight_and_value[i][WEIGHT],&weight_and_value[i][VALUE]);
    }

    printf("%d",MaxValueFunc(0,weight_and_value,0,0,MaxWeight,n));

    // int Maxvalue = 0;


    
    
    return 0;
}
