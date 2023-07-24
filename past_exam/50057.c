#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define ZERO 0
#define ONE 1
#define START -1

#define BITNUM 32
typedef unsigned int ui;

int main(void)
{
    int N;
    scanf("%d",&N);

    int status = START;
    ui testbit = (1 << 31);

    ui num;
    int prev_status = START;
    int now_status = START;
    int s = 0;
    for (int i = 0; i < N; i++){
        scanf("%u",&num);
        for (int j = 0; j < BITNUM; j++){
            now_status = (((num & testbit) == ZERO)? ZERO: ONE);
            if (prev_status != START && now_status != prev_status){
                // printf("dick");
                printf("\n");
                int time = s % 40;
                for (int i = 0; i < time; i++){
                    printf(" ");
                }
            }
            printf("%d",now_status);
            num <<= 1;
            prev_status = now_status;
            s++;
        }
    }
    
    return 0;
}
