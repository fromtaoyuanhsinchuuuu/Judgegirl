#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSTRING 100
#define RESULTNUM 4
int main(void)
{
    char str[MAXSTRING];
    scanf("%s",str);
    int result[RESULTNUM] = {};
    for (int i = 0; i < strlen(str); i++){
        char now_char = str[i];
        if (now_char >= 48 && now_char <= 57){
            result[0]++;
        }
        if ((now_char >= 65 && now_char <= 90) || (now_char >= 97 && now_char <= 122)){
            result[1]++;
        }
        if (now_char == 'a' || now_char == 'e' || now_char == 'i' || now_char == 'o' || now_char == 'u' ||now_char == 'A' || now_char == 'E' || now_char == 'I' || now_char == 'O' || now_char == 'U'){
            result[2]++;
        }
    }
    result[3] = result[1] - result[2];
    for (int i = 0; i < RESULTNUM; i++){
        printf("%d%c",result[i]," \n"[i == RESULTNUM-1]);
    }
    




    
    
    return 0;
}
