#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXARR 100

typedef long long ll;

int bits_count(ll n)
{
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < sizeof(ll) * 8; i++){
        if ((n & 1) != 0){
            count++;
        }
        n >>= 1;
    }
    
    return count;
}



int main(void)
{
    ll n;
    while (scanf("%lld",&n) != EOF){
        printf("%d\n",bits_count(n));


    }
    
    
    return 0;
}
