#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int bits_count(int n)
{
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++){
        if ((n & 1) != 0){
            count++;
        }
        else{
            if (count > max_count){
                max_count = count;
            }
            count = 0;
        }
        n >>= 1;
    }
    if (count > max_count){
        max_count = count;
    }
    
    return max_count;
}

int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF){
        printf("%d\n",bits_count(n));
    }
    
    
    return 0;
}



