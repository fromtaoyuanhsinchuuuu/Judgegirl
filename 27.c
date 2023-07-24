#include <stdio.h>

int main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int V,A;
    V = a*b*c - 2*d*((c-2*e)*(a-2*e)+(c-2*e)*(b-2*e)+(a-2*e)*(b-2*e));
    A = 2*(a*b+b*c+a*c) + 8*d*(a+b+c-6*e);
    printf("%d\n",A);
    printf("%d",V);
    
    return 0;
}



