#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int edge_num = a + b + c + d + (a + b + c) * e + (c + d) * f + e * g + g + f;
    int total = (a + b + c) * e * g + c * f + d * f;
    printf("%d\n%d",edge_num,total);
    
    
    return 0;
}
