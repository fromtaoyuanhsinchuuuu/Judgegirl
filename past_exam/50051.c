#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTRING 8
#define MAXN 30
#define FIRST 0
#define SECOND 1

bool in_arr_twice(int arr[MAXSTRING],int c,int N)
{
    int fit = 0;
    for (int i = 0; i < N; i++){
        if (arr[i] == c){
            fit++;
        }
        if (fit == 2){
            return 1;
        }
    }
    return 0;
}

bool all_suit(char str[MAXSTRING])
{
    bool second_have = (str[2] == '-');
    bool third_have = (str[3] == '-');
    if (!(second_have ^ third_have)){
        return 0;
    }
    /* 先檢查1,2 */
    int len = strlen(str);
    int digit_sum = 0;
    bool have_digit = 0;
    char prev = '\0';
    for (int i = 0; i < len; i++){
        if (str[i] == '4' && prev == '4'){
            return 0;
        }
        if (isdigit(str[i])){
            have_digit = 1;
            digit_sum += (str[i] - '0');
        }
        else if (!isalpha(str[i])){
            if (!((i == 2 || i == 3) && str[i] == '-')){
                return 0;
            }
        }
        prev = str[i];
    }
    if (digit_sum % 7 == 0 || !have_digit){
        return 0;
    }
    /* 檢查是否有同字元 */
    int pass_arr[MAXSTRING] = {};
    for (int i = 0; i < len; i++){
        if (in_arr_twice(pass_arr,str[i],i)){
            return 0;
        }
        else{
            pass_arr[i] = str[i];
        }
    }
}

void bubble_sort(char str[MAXN][MAXSTRING],int len)
{
    char temp[MAXSTRING];
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - 1; j++){
            if (strcmp(str[j],str[j + 1]) > 0){
                strcpy(temp,str[j + 1]);
                strcpy(str[j+1],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    
}

int main(void)
{
    int N;
    scanf("%d",&N);

    char str_type1[MAXN][MAXSTRING];
    char str_type2[MAXN][MAXSTRING];
    int type;
    int index1 = 0;
    int index2 = 0;
    char str_temp[MAXSTRING];
    for (int i = 0; i < N; i++){
        scanf("%s",str_temp);
        if (all_suit(str_temp)){
            if (str_temp[2] == '-'){
                strcpy(str_type1[index1],str_temp);
                index1++;
            }
            else if (str_temp[3] == '-'){
                strcpy(str_type2[index2],str_temp);
                index2++;
            }
            else{
                assert(0);
            }
        }
    }
    bubble_sort(str_type1,index1);
    bubble_sort(str_type2,index2);
    for (int i = 0; i < index1; i++){
        printf("%s\n",str_type1[i]);
    }
    for (int i = 0; i < index2; i++){
        printf("%s\n",str_type2[i]);
    }


    
    
    return 0;
}
