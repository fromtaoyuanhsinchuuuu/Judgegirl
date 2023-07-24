#include <stdio.h>

// int x[1025];
int main()
{
    int n;
    scanf("%d",&n);
    int x[n];
    for (int i = 0 ; i < n ; i++){
        int k;
        scanf("%d",&k);
        x[i] = k;
    }
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0 ; i < n ; i++){
        if (x[i]%2 == 1){
            odd_count += 1;
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (x[i]%2 == 0){
            even_count += 1;
        }
    }
    // printf("\n");
    // printf("%d %d",odd_count,even_count); 
    int odd_counting = 0;
    int even_counting = 0;

    for (int i = 0 ; i < n ; i++){
        if (x[i]%2 == 1 && odd_counting != odd_count-1){
            printf("%d ",x[i]);
            odd_counting += 1;
        }
        else if (x[i]%2 == 1)
        printf("%d",x[i]);
    } 
    // printf("kk");
    printf("\n");
    for (int i = 0 ; i < n ; i++){
        if (x[i]%2 == 0 && even_counting != even_count-1){
            printf("%d ",x[i]);
            even_counting += 1;
        }
        else if (x[i]%2 == 0)
        printf("%d",x[i]);
    } 
    // printf("\n");
    // printf("kk");
    return 0;
}
