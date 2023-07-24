#include <stdio.h>

int main(){
    long long x_limit,y_limit,X1,Y1,E1,N1,F1,X2,Y2,E2,N2,F2;
    int time = 0;
    int R1_pattern = 0; // 0表向上走,1表向右走
    int R1_pattern_count = 0;
    int R2_pattern = 0; // 0表向右走,1表向上走
    int R2_pattern_count = 0;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x_limit,&y_limit,&X1,&Y1,&E1,&N1,&F1,&X2,&Y2,&E2,&N2,&F2);
    // Robots will repeat the pattern
    while ((X1 != X2 || Y1 != Y2) && (F1 != 0 || F2 != 0))
    {
        // printf("\ntime:%d",time);
        // printf("\nR1(%d,%d)",X1,Y1);
        // printf("\nR2(%d,%d)",X2,Y2);
        // printf("\nR1_pattern:%d",R1_pattern);
        // printf("\nR1_pattern_count:%d",R1_pattern_count);
        // printf("\nR2_pattern:%d",R2_pattern);
        time += 1;
        if (F1 != 0){
            F1 -= 1;
            switch (R1_pattern)
            {
            case 0:
                if (R1_pattern_count == N1){
                    R1_pattern = 1;
                    R1_pattern_count = 0;
                }
                break;
            case 1:
                if (R1_pattern_count == E1){
                    R1_pattern = 0;
                    R1_pattern_count = 0;
                }
                break;
            default:
                break;
            }
            R1_pattern_count += 1;
            switch (R1_pattern)
            {
            case 0:
                if (Y1 != y_limit-1){
                    Y1 += 1;
                }
                else{
                    Y1 = 0;
                }
                break;
            case 1:
                if (X1 != x_limit-1){
                    X1 += 1;
                }
                else{
                    X1 = 0;
                }
                break;
            default:
                break;
            }
        }
        if (F2 != 0){
            F2 -= 1;
            switch (R2_pattern)
            {
            case 0:
                if (R2_pattern_count == E2){
                    R2_pattern = 1;
                    R2_pattern_count = 0;
                }
                break;
            case 1:
                if (R2_pattern_count == N2){
                    R2_pattern = 0;
                    R2_pattern_count = 0;
                }
                break;
            default:
                break;
            }
            R2_pattern_count += 1;
            switch (R2_pattern)
            {
            case 0:
                if (X2 != x_limit-1){
                    X2 += 1;
                }
                else{
                    X2 = 0;
                }
                break;
            case 1:
                if (Y2 != y_limit-1){
                    Y2 += 1;
                }
                else{
                    Y2 = 0;
                }
                break;
            default:
                break;
            }
        }
    }
    // printf("F1:%d,F2:%d",F1,F2);
    if (X1 == X2 && Y1 == Y2){
        printf("robots explode at time %d",time);
    }
    else{
        printf("robots will not explode");
    }
}