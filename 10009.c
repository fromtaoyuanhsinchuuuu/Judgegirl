#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

int gcd(int a,int b){
    if (a % b == 0){
        return b;
    }
    return (gcd(b,a % b));
}

int main(void)
{
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF){
        int gcd_num = gcd(a,b);
        printf("%d / %d\n",a / gcd_num,b / gcd_num);
    }

    
    
    return 0;
}
