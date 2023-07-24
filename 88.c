#include <stdio.h>

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int first_number[4],second_number[4];
    for(int i = 3 ; i >= 0 ; i--){
        first_number[i] = x%10;
        second_number[i] = y%10;
        y /= 10;
        x /= 10;
    }
    int A_COUNT = 0;
    int B_COUNT = 0;
    for(int i = 0 ; i <= 3 ; i++){
        for (int j = 0 ; j <= 3 ; j++){
            if (i == j && first_number[i] == second_number[j] ){ 
                A_COUNT += 1;
            }
            else if (first_number[i] == second_number[j]){
                B_COUNT += 1;
            }
            else{
                continue;
            }
        }
    }
    printf("%dA%dB",A_COUNT,B_COUNT);
    return 0;
}
