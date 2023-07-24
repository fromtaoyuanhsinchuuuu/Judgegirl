#include <stdio.h>
#include <stdbool.h>


void bubblesort_pointer(int *ptr[],int n)
{
    for (int i = 0; i < n-2; i++){
        for (int j = i; j < n-1; j++){
            if (ptr[i] > ptr[j]){
                int *temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

void fill_array(int *ptr[], int n)
{
    int max_array_num = ptr[n-1] - ptr[0] + 1;
    for (int i = 0; i < n; i++){
        *ptr[i] = i;
    }
    bubblesort_pointer(ptr,n);
    int diff_index_array[n];
    for (int i = 0; i < n ; i++){
        diff_index_array[i] = ptr[i] - ptr[0];
    }
    for (int i = 0; i < n; i++){
        // printf("*ptr[%d]:%d\n",i,*ptr[i]);
    }
    
    /* 用布林值存哪些有被指到 */
    // for (int i = 0; i < max(ptr[],n); i++){
    //     ptr2[i] = ptr[0]+i;
    // }
    // printf("max_array_num:%d\n",max_array_num);
    bool if_not_pointed_array[max_array_num];
    for (int i = 0; i < max_array_num; i++){
        bool if_not_pointed = 1;
        int array_index = i;
        // printf("array_index:%d\n",array_index);
        for (int j = 0; j < n; j++){
            if (diff_index_array[j] == array_index){
                if_not_pointed = 0;
                // printf("")
                break;
            }
        }
        if_not_pointed_array[i] = if_not_pointed;


    //     if(if_not_pointed){
    //         int diff_index;
    //         int bubblesort_array[10000];
    //         for (int j = 0; j < n; j++){
    //             bubblesort_array[j] = i - diff_index_array[j];

    //         }
    //         diff_index = bubblesot_array_and_return_min_pos(bubblesort_array,n);
    //         // printf("diff_index:%d\n",diff_index);
    //         *(ptr[0] + i) = *ptr[diff_index] + *ptr[diff_index+1];
    //         // printf("*array[%d]:%d\n",i,*(ptr[0]+i));

    //     }
    // }
    // // printf("sum:%d\n",*ptr[0]+*ptr[1]);
    }
    // for (int i = 0; i < max_array_num; i++){
    //     printf("%d ",if_not_pointed_array[i]);
    // }
    // printf("max_array_num:%d\n",max_array_num);
    // printf("\n");
    for (int i = 0; i < max_array_num; i++){
        if (if_not_pointed_array[i]){
            int sum = 0;
            int array_index = i;
            int *array_pointer = ptr[0]+i; /*指向array[i]的'位置'*/
            int *pointed_array_pointer = ptr[0]+i;
            // printf("pointed_index:%d\n",pointed_array_pointer-ptr[0]);

            /*向右找第一個被指到的*/
            while (if_not_pointed_array[pointed_array_pointer-ptr[0]]){
                // printf("ddci\n");

                pointed_array_pointer++;
            }
            sum += *pointed_array_pointer;
            // printf("i:%d sum:%d\n",i,sum);
            // printf("pointed_index:%d\n",pointed_array_pointer-ptr[0]);
            pointed_array_pointer = ptr[0] + i;
            while(if_not_pointed_array[pointed_array_pointer-ptr[0]]){
                pointed_array_pointer--;
            }
            sum += *pointed_array_pointer;
            *array_pointer = sum;
        }
    }
}







// #include "fill_array.h"
int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}