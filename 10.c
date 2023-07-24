#include <stdio.h>

int main()
{
    int a,b,x;
    scanf("%d%d",&a,&b);
    x = a;
    for(int i = 1 ; i < b ; i++){
        a = a*x;
    }
    printf("%d",a);

    
    return 0;
}
