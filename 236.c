#include <stdio.h>

int gcd(int a,int b)
{
    while (a % b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

int lcm(int a,int b)
{
    int lcm = a * b / gcd(a,b);
    return lcm;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int lcm_now = lcm(a,b);
    int x;
    while (scanf("%d",&x) != EOF){
        lcm_now = lcm(lcm_now,x);
    }
    printf("%d",lcm_now);
    return 0;
}
