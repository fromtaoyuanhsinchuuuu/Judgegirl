#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int digits[3];
    for(int i = 2  ; i >= 0 ; i--){
        digits[i] = x%10;
        x = (x-digits[i])/10;
    }
    for(int i = 0 ; i < 3 ; i++){
        printf("%d\n",digits[i]);
    }
    return 0;
}

