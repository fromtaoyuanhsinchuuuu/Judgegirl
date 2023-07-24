#include <stdio.h>

int main()
{
    int x;
    int score;
    scanf("%d",&x);
        if (x <= 0){
            score = -100;
        }
        else{
            score = 0;
        if (x%3 == 0){
            score += 3;
        }if (x%5 == 0){
            score += 5;
        }
        if ((x <= 200) && (x >= 100)){
            score += 50;
        }
        else{
            score -= 50;
        }
        }
    printf("%d",score);

    return 0;
}
