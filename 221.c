#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXM 256

void space_num_count(int space_num_arr[],int collect_num,int space_num)
{
    for (int i = 0; i < collect_num - 1; i++){
        space_num_arr[i] += (i < space_num % (collect_num - 1))? space_num / (collect_num - 1) + 1 :  space_num / (collect_num - 1);
    }

}

int main(void)
{
    int m;
    scanf("%d",&m);

    int nowline_char = 0;
    char now_string[MAXM];
    char string_collect[MAXM][MAXM];
    int collect_num = 0;
    int space_num;
    bool to_print;

    while (scanf("%s",now_string) != EOF){
        to_print = 1;
        if (nowline_char + strlen(now_string) == m){
            for (int i = 0; i < collect_num ; i++){
                printf("%s%c",string_collect[i],' ');
            }
            printf("%s\n",now_string);
            to_print = 0;
            collect_num = 0;
            nowline_char = 0;
        }
        else if (nowline_char + strlen(now_string) < m){
            strcpy(string_collect[collect_num],now_string);
            string_collect[collect_num][strlen(now_string)] = '\0';
            collect_num++;
            nowline_char += strlen(now_string) + 1;
        }
        else{
            space_num = m - nowline_char + collect_num;
            int space_num_arr[MAXM] = {0};
            space_num_count(space_num_arr,collect_num,space_num);
            if (collect_num > 1){
                for (int i = 0; i < collect_num - 1; i++){
                    printf("%s",string_collect[i]);
                    for (int j = 0; j < space_num_arr[i]; j++){
                        printf(" ");
                    }
                }
                printf("%s\n",string_collect[collect_num - 1]);
            }
            else{
                printf("%s",string_collect[collect_num - 1]);
                for (int i = 0; i < m - strlen(string_collect[0]); i++){
                    printf(" ");
                }
                printf("\n");
            }

            strcpy(string_collect[0],now_string);
            string_collect[0][strlen(now_string)] = '\0';
            collect_num = 1;
            nowline_char = strlen(now_string) + 1;
            /* 需要放空格的地方數 = collect_num - 1 */
        }
        // printf("now_char:%d\n",nowline_char);
    }
    space_num = m - nowline_char + collect_num;
    int space_num_arr[MAXM] = {0};
    space_num_count(space_num_arr,collect_num,space_num);
    if (collect_num > 1 && to_print){
        for (int i = 0; i < collect_num - 1; i++){
            printf("%s",string_collect[i]);
            for (int j = 0; j < space_num_arr[i]; j++){
                printf(" ");
            }
        }
        printf("%s\n",now_string);
    }
    else if (to_print){
        printf("%s",now_string);
        for (int i = 0; i < m - strlen(now_string); i++){
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
