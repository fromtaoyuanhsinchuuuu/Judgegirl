#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXN 100
#define MAXI 10
#define MAXSTRING 65 // 若題目給64，則至少設到65

void bubble_sort(char *ptr[MAXI],int common_num)
{
    for (int i = 0; i < common_num - 1; i++){
        for (int j = 0; j < common_num - 1; j++){
            if (strcmp(ptr[j],ptr[j + 1]) > 0){
                char *temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);

    char food[MAXN][MAXSTRING];
    char ingredient[MAXN][MAXI][MAXSTRING];
    int ingri_num_arr[MAXN] = {};

    for (int i = 0; i < n; i++){
        scanf("%s",food[i]);

        int ingri_num;
        scanf("%d",&ingri_num_arr[i]);

        for (int j = 0; j < ingri_num_arr[i]; j++){
            scanf("%s",ingredient[i][j]);
        }
    }
    
    int m;
    scanf("%d",&m);

    for (int i = 0; i < m; i++){
        char food1[MAXSTRING],food2[MAXSTRING];
        scanf("%s%s",food1,food2);
        int food1_index = -1;
        int food2_index = -1;
        int cmp_num = 0;
        for (int j = 0; j < n && cmp_num < 2; j++){
            if (!strcmp(food[j],food1)){
                food1_index = j;
                cmp_num++;
            }
            if (!strcmp(food[j],food2)){
                food2_index = j;
                cmp_num++;
            }
        }

        char common_arr[MAXI][MAXSTRING];
        char *common_ptr[MAXI];
        int common_num = 0;

        for (int ingri_1_index = 0; ingri_1_index < ingri_num_arr[food1_index]; ingri_1_index++){
            for (int ingri_2_index = 0; ingri_2_index < ingri_num_arr[food2_index]; ingri_2_index++){
                if (!strcmp(ingredient[food1_index][ingri_1_index],ingredient[food2_index][ingri_2_index])){
                    strcpy(common_arr[common_num],ingredient[food1_index][ingri_1_index]);
                    common_ptr[common_num] = common_arr[common_num];
                    common_num++;
                }
            }
        }
        if (common_num == 0){
            printf("nothing\n");
        }
        else{
            bubble_sort(common_ptr,common_num);
            for (int index = 0; index < common_num; index++){
                printf("%s%c",common_ptr[index]," \n"[index == common_num - 1]);
            }
        }
    }
    
    return 0;
}
