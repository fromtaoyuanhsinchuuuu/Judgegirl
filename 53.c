#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXARR 10

void bubble_sort(int arr[MAXARR],int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

bool in_the_arr(int now_index,int num,int arr[MAXARR])
{
    for (int i = 0; i <= now_index; i++){
        if (num == arr[i]){
            return 1;
        }
    }
    return 0;
}

void permutation(int array[MAXARR],int n,int nowIndex,int nownum,int permute_arr[MAXARR])
{
    permute_arr[nowIndex] = nownum;
    // printf("nowindex:%d nownum:%d\n",nowIndex,nownum);
    if (nowIndex == n - 1){
        for (int i = 0; i < n; i++){
            printf("%d%c",permute_arr[i]," \n"[i == n - 1]);
        }
        return;
    }
    for (int index = 0; index < n; index++){
        if (!in_the_arr(nowIndex,array[index],permute_arr)){
            permutation(array,n,nowIndex+1,array[index],permute_arr);
        }
    }
    return;
}

int main(void)
{
   int n;
   scanf("%d",&n);

   int array[MAXARR];
   for (int i = 0; i < n; i++){
    scanf("%d",&array[i]);
   } 
   bubble_sort(array,n);

    int permute_arr[MAXARR];
    for (int i = 0; i < n; i++){
        // printf("i:%d\n",i);
        permutation(array,n,0,array[i],permute_arr);
    }

    
    return 0;
}
