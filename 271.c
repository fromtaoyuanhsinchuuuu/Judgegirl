#include <stdio.h>

int main(void)
{
    int N1;
    scanf("%d",&N1);
    int pol_1[N1];
    for (int i = 0 ; i < N1 ; i++){
        scanf("%d",&pol_1[i]);
    }
    int N2;
    scanf("%d",&N2);
    int pol_2[N2];
    for (int i = 0 ; i < N2 ; i++){
        scanf("%d",&pol_2[i]);
    }
    int multiple_pol[N1+N2-1];
    for (int i = 0 ; i < N1+N2-1 ; i++){
        multiple_pol[i] = 0;
    }
    for (int i = 0 ; i < N1 ; i++){
        for (int j = 0 ; j < N2 ; j++){
            multiple_pol[i+j] += pol_1[i]*pol_2[j];
        }
    }
    for (int i = 0 ; i < N1+N2-1 ; i++){
        if (i != N1+N2-2)
            printf("%d ",multiple_pol[i]);
        else{
            printf("%d",multiple_pol[i]);
        }
    }


    
    return 0;
}
