#include <stdio.h>

int main()
{
    int w,a,b,c,d,e;
    scanf("%d%d%d%d%d%d",&w,&a,&b,&c,&d,&e);
    int distance;
    if (b > 0){
        distance = (a+b+c+2+2*d+2*e)*(a+b+c+2+2*d+2*e)+w*w;
    }
    else{
        distance = (2*((d-e > 0) ?d:e)+a+c+2)*(2*((d-e > 0) ?d:e)+a+c+2)+w*w;
    }
    printf("%d",distance);
    return 0;
}

