#include <stdio.h>

int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int time = 0;
    long long sol_array[3] = {-100001,-100001,-100001};
    for (long long x = 100000 ; x >= -100000 ; x--){
        long long sol = x*x*x + a*x*x + b*x + c;
        if (sol == 0){
            sol_array[time] = -x;
            time++;
        }
    }
    if (sol_array[1] == -100001){
        printf("%d %d %d",sol_array[0],sol_array[0],sol_array[0]);
    }
    else if (sol_array[2] == -100001){
        if (b == 0 && c == 0){
            if (sol_array[0] == 0){
                printf("%d %d %d",0,0,sol_array[1]);
            }
            else{
                printf("%d %d %d",sol_array[0],0,0);
            }
        }
        else if (c == 0){
            if (sol_array[0] == 0){
                printf("%d %d %d",0,sol_array[1],sol_array[1]);
            }
            else{
                printf("%d %d %d",sol_array[0],sol_array[0],0);
            }
        }
        else{
            int third = c/(sol_array[0]*sol_array[1]);
            if (third <= sol_array[0]){
                printf("%d %d %d",third,sol_array[0],sol_array[1]);
            }
            else{
                printf("%d %d %d",sol_array[0],sol_array[1],sol_array[1]);
            }
        }
    }
    else{
        printf("%d %d %d",sol_array[0],sol_array[1],sol_array[2]);
    }
    
    
    return 0;
}
