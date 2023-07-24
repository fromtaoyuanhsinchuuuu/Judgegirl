#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSTRING 10

bool neep_to_print_space(int w,int h,int now_row,int now_col)
{
    if (((now_col == 0 || now_col == w - 2) && (now_row == 0 || now_row == h / 2 || now_row == h - 1))){
        printf(" ");
        return 1;
    }
    if (!(now_row == 0 || now_row == h / 2 || now_row == h - 1) && !(now_col == 0 || now_col == w - 2)){
        printf(" ");
        return 1;

    }
    if (now_col == w - 1){
        printf(" ");
        return 1;

    }
    return 0;
}


int main(void)
{
    char numstring[MAXSTRING];
    while (scanf("%s",numstring) != EOF){
        int w,h; // 4 < w < 9 , 5 < h < 15 
        scanf("%d%d",&w,&h);
        for (int now_row = 0; now_row < h; now_row++){
            for (int index = 0; index < strlen(numstring); index++){
                char now_num = numstring[index];
                for (int now_col = 0; now_col < w; now_col++){
                    if (neep_to_print_space(w,h,now_row,now_col)){
                        continue;
                    }
                    switch (now_num)
                    {
                        case '0':
                            if (now_row != h / 2){
                                printf("0");
                            }
                            else{
                                printf(" ");
                            }
                            break;
                        case '1':
                            if (now_col == w - 2 && !(now_row == 0 || now_row == h / 2 || now_row == h - 1)){
                                printf("1");
                            }
                            else{
                                printf(" ");
                            }
                            break;
                        case '2':
                            if (now_col == 0 && now_row < h / 2 || now_col == w - 2 && now_row > h / 2){
                                printf(" ");
                            }
                            else{
                                printf("2");
                            }
                            break;
                        case '3':
                            if (now_col == 0){
                                printf(" ");
                            }
                            else{
                                printf("3");
                            }
                            break;
                        case '4':
                            if (now_row == 0 || now_row == h - 1 || now_col == 0 && now_row > h / 2){
                                printf(" ");
                            }
                            else{
                                printf("4");
                            }
                            break;
                        case '5':
                            if (now_col == w - 2 && now_row < h / 2 || now_col == 0 && now_row > h / 2){
                                printf(" ");
                            }
                            else{
                                printf("5");
                            }
                            break;
                        case '6':
                            if (now_col == w - 2 && now_row < h / 2){
                                printf(" ");
                            }
                            else{
                                printf("6");
                            }
                            break;
                        case '7':
                            if (now_row == h / 2 || now_row > h / 2 && now_col != w - 2){
                                printf(" ");
                            }
                            else{
                                printf("7");
                            }
                            break;
                        case '8':
                            printf("8");
                            break;
                        case '9':
                            if (now_row > h / 2 && now_col != w - 2){
                                printf(" ");
                            }
                            else{
                                printf("9");
                            }
                            break;
                    }
                }
            }
            printf("\n");
        }

        
    }

    
    return 0;
}
