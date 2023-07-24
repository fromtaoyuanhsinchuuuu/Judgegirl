#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 501
#define MAXCOUNT 20000

typedef struct {
    int count;
    char str_arr[500][MAXSTR];
} Ans;

void select(char *str,int index,char *now_str,Ans *ans)
{
    if (index == strlen(str)){
        strcpy(ans->str_arr[ans->count],now_str);
        ans->count++;

        printf("%s\n",now_str);
        return;
    }

    char select_str[MAXSTR],not_select_str[MAXSTR];
    strcpy(select_str,now_str);
    strcpy(not_select_str,now_str);

    select_str[strlen(now_str)] = str[index];
    select_str[strlen(now_str) + 1] = '\0';

    select(str,index + 1,select_str,ans);
    select(str,index + 1,not_select_str,ans);

    return;

}

int main(void)
{
    char str[MAXSTR];
    scanf("%s",str);

    char now_str[MAXSTR] = "\0";

    Ans ans;
    ans.count = 0;

    select(str,0,now_str,&ans);




   
    
    return 0;
}
