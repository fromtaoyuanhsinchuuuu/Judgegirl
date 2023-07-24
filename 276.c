#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRING 128
#define MAXNUM 128

int main(void)
{
    char now_string[MAXSTRING];
    char now_string_arr[MAXNUM][MAXSTRING];
    int arr_index = 0;
    while (scanf("%s",now_string) != EOF){
        if (now_string[strlen(now_string) - 1] != '.'){
            strcpy(now_string_arr[arr_index],now_string);
            arr_index++;
        }
        else{
            strcpy(now_string_arr[arr_index],now_string);
            arr_index++;
            for (int i = 0; i < arr_index; i++){
                if (!strcmp(now_string_arr[i],"at") || !strcmp(now_string_arr[i],"and") || !strcmp(now_string_arr[i],"of") || !strcmp(now_string_arr[i],"the")
                    || !strcmp(now_string_arr[i],"at.") || !strcmp(now_string_arr[i],"and.") || !strcmp(now_string_arr[i],"of.") || !strcmp(now_string_arr[i],"the.")){
                    continue;
                }
                else{
                    printf("%c",now_string_arr[i][0] - 32);
                }
            }
            printf("\n");
            arr_index = 0;
        }
    }

    
    
    return 0;
}
