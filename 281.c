#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int bits_count(int n)
{
    int count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++){
        if ((n & 1) != 0){
            count++;
        }
        n >>= 1;
    }
    
    return count;
}

int main(void)
{
    int n;

    while (scanf("%d",&n) != EOF){
        printf("%d\n",bits_count(n));
    }

    return 0;
}
