#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTRING 100
#define ARRSIZE 1000
#define LETTER 26

void bubble_sort(char str[MAXSTRING])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - 1; j++){
            if (str[j] > str[j + 1]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}


bool violate(char nowstring[MAXSTRING],char rules_arr[ARRSIZE][MAXSTRING],int n)
{
    for (int i = 0; i < n; i++){
        if (strstr(nowstring,rules_arr[i]) != NULL){
            return 1;
        }
    }
    return 0;

}

void init_arr(int letter_count[LETTER])
{
    for (int i = 0; i < LETTER; i++){
        letter_count[i] = 0;
    }
}

char letter_func(char nowstring[MAXSTRING],int letter_arr[LETTER])
{
    int len = strlen(nowstring);
    int letter_count[LETTER] = {};
    for (int i = 0; i < len; i++){
        letter_count[nowstring[i] - 97]++;
    }
    for (int i = 0; i < LETTER; i++){
        if (letter_count[i] < letter_arr[i]){
            return (i + 97);
        }
    }
    return 0;
}

void permutation(char nowstring[MAXSTRING],char rules_arr[ARRSIZE][MAXSTRING],int n,int nowIndex,int len,int letter_arr[LETTER],char letter)
{

    return 1;
}

int main(void)
{
    char str[MAXSTRING];
    scanf("%s",str);

    bubble_sort(str);
    // printf("%s",str);

    int n;
    scanf("%d",&n);

    int len = strlen(str);
    int letter_arr[LETTER] = {};
    /* count letter number */
    for (int i = 0; i < len; i++){
        letter_arr[str[i] - 97]++;
    }
    int letter_count[LETTER] = {};

    char nowstring[MAXSTRING];
    nowstring[0] = '\0';

    char rules_arr[ARRSIZE][MAXSTRING];
    for (int i = 0; i < n; i++){
        scanf("%s",rules_arr[i]);
    }

    for (int i = 0; i < len; i++){
        permutation(nowstring,rules_arr,n,0,len,letter_arr,nowstring[i]);
    }






    
    
    return 0;
}
