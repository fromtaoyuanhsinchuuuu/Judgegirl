#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 1024

int main(void)
{
    char str[MAXSTR];
    while (scanf("%s",str) != EOF){
        int len = strlen(str);
        int index = 0;
        while (index != len){
            while (!isdigit(str[index]) && index != len){
                index++;
            }

            char num[MAXSTR];
            int num_index = 0;

            while (isdigit(str[index + num_index]) && index != len){
                num[num_index] = str[index + num_index];
                num_index++;
            }
            index += num_index;
            num[num_index] = '\0';
            if (num_index > 0){
                printf("%d\n",atoi(num));
            }
        }




    }
    
    
    return 0;
}
