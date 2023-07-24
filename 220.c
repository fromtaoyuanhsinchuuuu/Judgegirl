#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAXSENTENCE 10000
int main(void)
{
    char symbol;
    int count = 0;
    char after_dot;
    char after_after_dot;
    int change_line_symbol_count = 0;
    int dick = 1;
    char prev_symbol;
    while (scanf("%c",&symbol) != EOF){
        // if (symbol == '\n')
        //     change_line_symbol_count++;
        if (symbol != '\n')
            prev_symbol = symbol;
        if (symbol == '.'){
            // char after_dot;
            
            scanf("%c",&after_dot);
            prev_symbol = after_dot;
            if (after_dot == '\n'){
                count++;
            }
            // else if (after_dot == '.'){
            //     dick = 0;
            // }
            else if (after_dot == ' '){
                // char after_after_dot;
                scanf("%c",&after_after_dot);
                if (after_after_dot == ' '){
                    count++;
                }
            }
        }
    }
    if (prev_symbol == '.' && count == 0){
        printf("%d",count+1);
    }
    else{
        printf("%d",count);
    }
    return 0;
}
