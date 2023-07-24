#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAXSTRING 100

int main(void)
{
    char ans_str[MAXSTRING];
    char now_char;
    int str_index = 0;
    bool meet_first_valid_char = 0;
    while (scanf("%c",&now_char) != EOF){
        if (!(isspace(now_char)) || meet_first_valid_char){
            ans_str[str_index] = now_char;
            str_index++;
            meet_first_valid_char = 1;
        }
    }
    for (int i = strlen(ans_str) - 2; i > 0; i--){
        if (isspace(ans_str[i])){
            ans_str[i] = '\0';
        }
        else{
            break;
        }
    }
    printf("%s",ans_str);
    return 0;
}
