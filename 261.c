#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTRING 10
#define LETTER 26
typedef unsigned long long ull;

typedef struct solution{
    ull num1;
    ull num2;
} Solution;


bool in_arr(int letter_ascii_arr[LETTER],int letter)
{
    for (int i = 0; i < LETTER; i++){
        if (letter == letter_ascii_arr[i]){
            return 1;
        }
    }
    return 0;

}

int transfer(char str[MAXSTRING],int decode_arr[MAXSTRING],int letter_ascii_arr[LETTER],int letter_num)
{
    int len = strlen(str);
    char num[MAXSTRING];
    strcpy(num,str);
    for (int i = 0; i < len; i++){
        for (int j = 0; j < letter_num; j++){
            if (num[i] == letter_ascii_arr[j]){
                num[i] = decode_arr[j] + 48;
            }
        }
    }
    
    return atoi(num);

}

void puzzle_sol(int decode_arr[MAXSTRING],char str1[MAXSTRING],char str2[MAXSTRING],int letter_ascii_arr[LETTER],int letter_num,char ans_str[MAXSTRING],int ans_arr[3])
{
    int num1 = transfer(str1,decode_arr,letter_ascii_arr,letter_num);
    int num2 = transfer(str2,decode_arr,letter_ascii_arr,letter_num);
    int ans = transfer(ans_str,decode_arr,letter_ascii_arr,letter_num);

    // printf("%d x %d = %d\n",num1,num2,ans);
    if (num1 * num2 == ans){
        ans_arr[0] = num1;
        ans_arr[1] = num2;
        ans_arr[2] = ans;
        return;
    }
    decode_arr[letter_num - 1]++;
    for (int i = letter_num - 1; i >= 0; i--){
        if (decode_arr[i] == 10){
            decode_arr[i - 1]++;
            decode_arr[i] = 1;
        }
    }
    puzzle_sol(decode_arr,str1,str2,letter_ascii_arr,letter_num,ans_str,ans_arr);
    return;
}

int main(void)
{
    int decode_arr[MAXSTRING];
    char str1[MAXSTRING],str2[MAXSTRING],ans_str[MAXSTRING];
    scanf("%s%s%s",str1,str2,ans_str);
    int letter;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ans_len = strlen(ans_str);
    int letter_ascii_arr[LETTER] = {};
    int letter_num = 0;
    int ans_arr[3];
    for (int i = 0; i < len1; i++){
        if (!in_arr(letter_ascii_arr,str1[i] && isalpha(str1[i]))){
            letter_ascii_arr[letter_num] = str1[i];
            letter_num++;
        }
    }
    for (int i = 0; i < len2; i++){
        if (!in_arr(letter_ascii_arr,str2[i]) && isalpha(str2[i])){
            letter_ascii_arr[letter_num] = str2[i];
            letter_num++;
        }
    }  // 未照順序排
    for (int i = 0; i < ans_len; i++){
        if (!in_arr(letter_ascii_arr,ans_str[i]) && isalpha(ans_str[i])){
            letter_ascii_arr[letter_num] = ans_str[i];
            letter_num++;
        }
    }
    // for (int i = 0; i < letter_num; i++){
    //     printf("%c ",letter_ascii_arr[i]);
    // }
    for (int i = 0; i < letter_num; i++){
        decode_arr[i] = 1;
    }

    puzzle_sol(decode_arr,str1,str2,letter_ascii_arr,letter_num,ans_str,ans_arr);
    printf("%d x %d = %d\n",ans_arr[0],ans_arr[1],ans_arr[2]);
    
    return 0;
}
