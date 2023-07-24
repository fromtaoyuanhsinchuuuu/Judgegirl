/* x=雞,y=兔,z=螃蟹
    x+y+z=s
    2x+4y+8z=f
    x+y=t 
    s=總數,f=腳數,t=尾數
    */
#include <stdio.h>

int main()
{
    int s,f,t;
    scanf("%d%d%d",&s,&f,&t);
    int x = -0.5*f-2*t+4*s;
    int y = 0.5*(f+6*t-8*s);
    int z = s-t;
    // if ((z == s-t) && (z >= 0)){
    // printf("%f\n", s-t);
    // printf("%d",z);}
    if((x >= 0) && (y >= 0) && (z >= 0 ) && (x == -0.5*f-2*t+4*s) && (y == 0.5*(f+6*t-8*s)) && (z == s-t)){
        printf("%d\n%d\n%d",x,y,z);
    }
    else{
        printf("0");
    }


    return 0;
}

