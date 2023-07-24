#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int square(int i,int n,int sum)
{
    if (i == n + 1){
        return sum;
    }
    sum += i * i;
    return(square(i+1,n,sum));
}

int main(void)
{
    int n;
    scanf("%d",&n);
    
    printf("%d",square(1,n,0));
    
    
    return 0;
}
