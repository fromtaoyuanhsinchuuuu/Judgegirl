#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int li[n];
    for (int i = 0 ; i < n ; i++){
        int a;
        scanf("%d",&a);
        li[i] = a;
    }
    for (int i = n-1 ; i > 0 ; i--){
        printf("%d ",li[i]);
    }
    printf("%d",li[0]);
    
    return 0;
}
