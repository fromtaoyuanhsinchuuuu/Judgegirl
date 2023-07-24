#include <stdio.h>

long long factorial(int k)
{
    long long result = 1;
    for(int i = 2 ; i <= k ; i++){
        result *= i;
    }
    return result;
}

int conbinaition_fuction(int a,int b)
{
    int result = factorial(a)/(factorial(b)*factorial(a-b));
    return result;
}

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int sum = 1;
    for (int i = 1 ; i <= n ; i++){
        sum += conbinaition_fuction(m,i);
    }
    printf("%d",sum);
    return 0;
}
