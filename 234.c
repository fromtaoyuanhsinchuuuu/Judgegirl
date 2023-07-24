#include <stdio.h>
#define one_sum d+e+f
#define two_sum d*e+e*f+d*f
#define three_sum d*e*f

int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    // d+e+f = a , de+ef+df = b , def =c (f>=e>=d)
    int d = -5000 ,e = -5000,f = -5000;
    int min_d = d;
    int min_e = e;
    while (!(one_sum == a && two_sum == b && three_sum== c))
    {
        f++;
        for (int i = f ; !(one_sum == a && two_sum == b && three_sum== c) && i >= min_d ; i--){
            d = i;
            for (int j = d ; !(one_sum == a && two_sum == b && three_sum== c) && j >= min_e ; j--){
                e = j;

            }
            
        }
    }
    printf("%d %d %d",e,d,f);
    



    
    return 0;
}
