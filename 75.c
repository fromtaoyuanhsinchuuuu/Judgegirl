#include <stdio.h>
#include <string.h>
#define MAXSTRING 100

int main(void)
{
    char str1[MAXSTRING];
    scanf("%s",str1);
    int letter_counts[26] = {};
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < strlen(str1); j++){
            if (str1[j] == i + 65 || str1[j] == i + 97){
                letter_counts[i]++;
            }
        }
    }
    for (int i = 0; i < 26; i++){
        printf("%d\n",letter_counts[i]);
    }
    
    
    
    return 0;
}
