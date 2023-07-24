#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAXSTRING 128

bool if_cat(int check_length,char ans_str[MAXSTRING],char now_str[MAXSTRING])
{
    for (int ans_str_index = strlen(ans_str) - check_length,now_str_index = 0; now_str_index < check_length; ans_str_index++,now_str_index++){
        if (ans_str[ans_str_index] != now_str[now_str_index]){
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    char ans_str[MAXSTRING];
    scanf("%s",ans_str);
    char now_str[MAXSTRING];
    while (scanf("%s",now_str) != EOF){
        int check_length;
        int now_ans_str_len = strlen(ans_str);
        for (check_length = strlen(ans_str); check_length >= 0; check_length--){
            if (if_cat(check_length,ans_str,now_str)){
                break;
            }
        }
        // printf("check_length:%d\n",check_length);
        // printf("ans_str_len:%d\n",strlen(ans_str));
        for (int time = 0,cat_index = check_length; time < strlen(now_str) - check_length; time++,cat_index++){
            ans_str[now_ans_str_len + time ] = now_str[cat_index];
            // printf("time:%d\n",time);
            // printf("anw_str_index:%d\n",strlen(ans_str) + time);
            // printf("cat_Index:%d\n",cat_index);
        }
        ans_str[strlen(now_str) + now_ans_str_len - check_length] = '\0';
    }
    printf("%s\n",ans_str);
    
    return 0;
}
