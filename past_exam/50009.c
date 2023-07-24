#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
 
int snake(int *ptr, int *row, int *column) {
    int arr_index = 1;
    int prev_num = ptr[0];
    int col_num = 1;
    while (ptr[arr_index] - prev_num == 1 && ptr[arr_index] != 0){
        prev_num = ptr[arr_index];
        col_num++;
        arr_index++;
    }
    // arr_index = col_num 
    *column = col_num;
    int diff = -1;
    while (1){
        prev_num = ptr[arr_index];
        for (int time = 0; time < col_num - 1; time++){
            if (ptr[arr_index + 1] - prev_num == diff && ptr[arr_index + 1] != 0){
                prev_num = ptr[arr_index + 1];
                arr_index++;
            }
            else if (ptr[arr_index + 1] - prev_num != diff && ptr[arr_index + 1] == 0){
                *row = (arr_index + 1) / col_num;
                return 1;
            }
            else{
                *row = (arr_index + 1) / col_num; 
                if (diff == -1){
                    *column = (col_num - 1) - (arr_index + 1) % col_num;
                }
                else{
                    *column = (arr_index + 1) % col_num;
                }
                return 0;
            }
        }

        if (diff == -1){
            if (ptr[arr_index + 1] - ptr[arr_index] != col_num && ptr[arr_index + 1]){
                *column = 0;
                *row = (arr_index + 1) / col_num;
                return 0;
            }
            diff = 1;
        }
        else{
            if (ptr[arr_index + 1] - ptr[arr_index] != col_num && ptr[arr_index + 1]){
                *column = col_num - 1;
                *row = (arr_index + 1) / col_num;
                return 0;
            }
            diff = -1;
        }

        assert(diff == -1 || diff == 1);

        arr_index++;
    }
    return 0;
}



int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}