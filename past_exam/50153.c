#include <stdio.h>

int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int length = a + c + e;
    int width = b + d + f;
    printf("%d\n",(length+width)*2);
    printf("%d",length*width-(b+d)*(c+e)+c*d);
    return 0;
}
