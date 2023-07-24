#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAXSTRING 80

int abs(int a)
{
    return (a >= 0)? a : -a;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    char str1[MAXSTRING];
    char str2[MAXSTRING];
    char *ptr1 = str1;
    char *ptr2 = str2;
    
    for (int i = 0; i < n; i++){
        scanf("%s%s",str1,str2);
        bool not_similar = 1;
        int result = strcmp(ptr1,ptr2);
        if (!result){
            printf("yes\n");
            not_similar = 0;
            continue;
        }
        else if (abs(strlen(str1) - strlen(str2)) == 1){
            if (strlen(ptr1) - strlen(ptr2) == -1){
                char *temp = ptr1;
                ptr1 = ptr2;
                ptr2 = temp;
            }
            int bidden_index = 0;
            for (int i = 0; i < strlen(ptr1); i++){
                char cmp_str[MAXSTRING];
                int string_index = 0;
                for (int in_index = 0; in_index < strlen(ptr1); in_index++){
                    if (in_index == bidden_index){
                        continue;
                    }
                    else{
                        cmp_str[string_index] = ptr1[in_index];
                        string_index++;
                    }
                }
                cmp_str[strlen(ptr2)] = '\0';
                // printf("cmp:%s ptr2:%s \n",cmp_str,ptr2);
                if (strcmp(cmp_str,ptr2) == 0){
                    printf("yes\n");
                    not_similar = 0;
                    break;
                }
                bidden_index++;
            }

        }
        else if (strlen(ptr1) == strlen(ptr2)){
            for (int switch_index = 0; switch_index < strlen(ptr1) - 1; switch_index++){
                char temp_str[MAXSTRING];
                int temp_str_index = 0;
                for (int str1_index = 0; str1_index < strlen(ptr1); str1_index++){
                    if (str1_index == switch_index){
                        temp_str[temp_str_index] = ptr1[str1_index + 1];
                    }
                    else if (str1_index == switch_index + 1){
                        temp_str[temp_str_index] = ptr1[str1_index - 1];
                    }
                    else{
                        temp_str[temp_str_index] = ptr1[str1_index];
                    }
                    temp_str_index++;
                }
                // printf("temp_str:%s\n",temp_str);
                temp_str[strlen(ptr1)] = '\0';
                if (!strcmp(temp_str,ptr2)){
                    printf("yes\n");
                    not_similar = 0;
                    break;
                }
            }
            
        }
        if (not_similar){
            printf("no\n");
        }
    }
    return 0;
}
