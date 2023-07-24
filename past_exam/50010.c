#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXSTRING 100000

int main(void)
{
    char str[MAXSTRING];
    scanf("%s", str);

    char *ptr = str;

    char command[MAXSTRING];
    int len;
    while (scanf("%s",command) != EOF){
        len = strlen(str);
        if (!strcmp(command,"replace")){
            char a,b;
            scanf(" %c %c",&a,&b);
            for (int i = 0; i < len; i++){
                if (str[i] == a){
                    str[i] = b;
                }
            }
        }
        else if (!strcmp(command,"remove")){
            char a;
            scanf(" %c",&a);
            for (int i = 0; i < len; i++){
                if (str[i] == a && i != 0 && i != strlen(str) - 1){
                    str[i] = '\0';
                    strcat(ptr,ptr+i+1);
                    i = -1;
                    len--;
                }
                else if (str[i] == a && i == 0){
                    strcpy(str,ptr+1);
                    i = -1;
                    len--;
                }
                else if (str[i] == a && i == strlen(str) - 1){
                    str[i] = '\0';
                    i = -1;
                    len--;
                }
            }
        }
        else if (!strcmp(command,"addhead")){
            char a[MAXSTRING];
            scanf("%s",a);
            strcat(a,str);
            strcpy(str,a);
        }
        else if (!strcmp(command,"addtail")){
            char a[MAXSTRING];
            scanf("%s",a);
            strcat(str,a);
            
        }
        else if (!strcmp(command,"end")){
            printf("%s\n",str);
            break;
        }
        else{
            printf("invalid command %s\n",command);
            break;
        }
        
    }
    
    return 0;
}
