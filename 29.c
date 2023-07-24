#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int goMaxtrix(int r,int c,int nowR,int nowC)
{
    if (nowR == r - 1 && nowC == c - 1){
        return 1;
    }
    if (nowR == r - 1 && nowC < c - 1){
        return(goMaxtrix(r,c,nowR,nowC+1));
    }
    if (nowC == c - 1 && nowR < r - 1){
        return(goMaxtrix(r,c,nowR+1,nowC));
    }
    return(goMaxtrix(r,c,nowR,nowC+1) + goMaxtrix(r,c,nowR+1,nowC));
}

int main(void)
{
    int r,c;
    scanf("%d%d",&r,&c);

    printf("%d",goMaxtrix(r,c,0,0));


    
    
    return 0;
}
