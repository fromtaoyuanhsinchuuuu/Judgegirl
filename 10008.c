#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    int dollar;
    while (scanf("%d",&dollar) != EOF){
        int x = 1000;
        int arr[7] = {};
        int index = 0;
        while (dollar != 0){
            while (dollar - x >= 0 && x != 0){
                arr[index]++;
                dollar -= x;
            }
            x /= 2;
            index++;
            while (dollar - x >= 0 && x != 0){
                arr[index]++;
                dollar -= x;
            }
            x /= 5;
            index++;
            if (dollar == 0){
                break;
            }
            continue;
        }
        for (int i = 0; i < 7; i++){
            printf("%d%c",arr[i]," \n"[i == 6]);
        }


    }
    
    
    return 0;
}
