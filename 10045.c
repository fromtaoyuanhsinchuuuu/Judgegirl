#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

int h_func(int x)
{
    if (x < 2){
        return -1;
    }
    return 2 + h_func(x - 1) - h_func(x - 2);
}

int g_func(int x)
{
    if (x <= 2){
        return x * x - 1;
    }
    return 2;
}

int f_func(int x)
{
    if (x > h_func(x)){
        return f_func(x - 1) - h_func(x);
    }
    if (x < h_func(x)){
        return f_func(g_func(x)) - g_func(x);
    }
    return 1;

}


int main(void)
{
    int x;
    scanf("%d",&x);

    printf("%d\n",f_func(x));
   
    
    return 0;
}
