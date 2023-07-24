#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXN 100000
#define MAXWORD 101

int abs(int a)
{
    return (a >= 0)? a: -a;
}

bool remove_or_insert(const char  *ptr1,const char  *ptr2) // str1比較長
{
    int len = strlen(ptr2);
    int err_count = 0;
    int i = 0;
    // printf("ptr1:%s ptr2:%s\n",ptr1,ptr2);
    if (strstr(ptr1,ptr2) != NULL){
        // printf("not null!\n");
        return 1;
    }
    
    while (1){
        if (ptr1[i] == ptr2[i]){
            i++;
        }
        else{
            if (!strcmp(ptr1+i+1,ptr2+i)){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    return 0;
    
}

bool cmp_func(char *str1,char *str2,char possible_arr[MAXN][MAXWORD],int arr_index)
{
    
    if (strlen(str1) - strlen(str2) == 0){
        int len = strlen(str1);
        int err_count = 0;
        for (int i = 0; i < len; i++){
            if (str1[i] != str2[i]){
                err_count++;
            }
            if (err_count > 1){
                return 0;
            }
        }
        strcpy(possible_arr[arr_index],str1);
        return 1;
    }
    else if (strlen(str1) - strlen(str2) == 1){ /* dict_str比較長 */
        if (remove_or_insert(str1,str2)){
            strcpy(possible_arr[arr_index],str1);
            return 1;
        }
    }
    else if (strlen(str2) - strlen(str1) == 1){
        if (remove_or_insert(str2,str1)){
            strcpy(possible_arr[arr_index],str1);
            return 1;
        }
    }
    return 0;
}


int main(void)
{
    int n;
    scanf("%d",&n);

    static char dict[MAXN][MAXWORD];
    for (int i = 0; i < n; i++){
        scanf("%s",dict[i]);
    }

    int q;
    scanf("%d",&q);

    char str[MAXWORD];
    static char possible_arr[MAXN][MAXWORD];
    for (int i = 0; i < q; i++){
        scanf("%s",str);
        bool is_same = 0;
        int arr_count  = 0;
        for (int j = 0; j < n; j++){
            if (!strcmp(str,dict[j])){
                /* check same */
                printf(">%s\n",str);
                is_same = 1;
                break;
            }
            if (cmp_func(dict[j],str,possible_arr,arr_count)){
                // printf("dict[%d]:%s\n",j,dict[j]);
                arr_count++;
            }
        }
        // printf("issame:%d arr_count:%d\n",is_same,arr_count);
        if (arr_count != 0 && !is_same){
            printf("?");
            for (int i = 0; i < arr_count; i++){
                printf("%s%c",possible_arr[i]," \n"[i == arr_count - 1]);
            }
        }
        else if (!is_same && arr_count == 0){
            printf("!%s\n",str);

        }
        
        

    }
    
    return 0;
}
