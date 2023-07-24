#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int ui;
#define MAXBIT 100
#define MAXARR 1024

int main(void)
{

    int w,h;
    scanf("%d%d",&w,&h);

    // char space;
    // scanf("%c",&space);

    char one_sym,zero_sym;
    scanf(" %c %c",&one_sym,&zero_sym);
    // scanf("%c",&zero_sym);

    // printf("space:%c\n",space);
    // printf("one_sym:%c zero_sym%c\n",one_sym,zero_sym);

    


    ui n;
    int bitmap[MAXARR][MAXBIT] = {};
    int arr_index = 0;

    while (scanf("%u",&n) != EOF){
        // printf("arr_index:%d\n",arr_index);
        for (int i = sizeof(ui) * 8 - 1; i >= 0; i--){
            if (n & 1 != 0){
                bitmap[arr_index][i] = 1;
                // printf("i:%d\n",i);
                // printf("bitmap[%d][%d]:%d\n",arr_index,i,bitmap[arr_index][i]);
            }
            n >>= 1;
        } 
        arr_index++;
    }
    // for (int i = 0; i < 32; i++){
    //     printf("%d",bitmap[0][i]);
    // }
    int count = 0;
    arr_index = 0;

    for (int i = 0; i < w * h; i++,count++){
        if (count == 32){
            count = 0;
            arr_index++;
        }
        if (bitmap[arr_index][count]){
            printf("%c",one_sym);
        }
        else{
            printf("%c",zero_sym);
            
        }
        if (i % w == w - 1){
            printf("\n");
        }
    }


    
    
    return 0;
}
