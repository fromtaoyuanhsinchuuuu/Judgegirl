#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 16
#define MAXSTR 16
#define MAXINT 2147483647

int min_index(int end_arr[],int N,int num_arr[])
{
    int min_ = MAXINT,minIndex = -1;
    for (int i = 0; i < N; i++){
        if (!end_arr[i]){
            if (num_arr[i] < min_){
                min_ = num_arr[i];
                minIndex = i;
            }

        }
    }

    return minIndex;
    
}

int main(void)
{
    int N;
    scanf("%d",&N);

    char str_arr[MAXN][MAXSTR];
    for (int i = 0; i < N; i++){
        scanf("%s",str_arr[i]);
    }

    FILE *fp;
    int num_arr[MAXN];
    for (int i = 0; i < N; i++){
        fp = fopen(str_arr[i],"rb");
        assert(fp != NULL);
        fread(&num_arr[i],sizeof(int),1,fp);
    }

    int end_arr[MAXN] = {};
    int count_arr[MAXN] = {};
    while (1){
        int index = min_index(end_arr,N,num_arr);
        if (index == -1){
            break;
        }

        printf("%d\n",num_arr[index]);
        count_arr[index]++;
        // printf("count:%d\n",count_arr[index]);
        FILE *fp;
        fp = fopen(str_arr[index],"rb");
        fseek(fp,count_arr[index] * sizeof(int),SEEK_SET);
        

        fread(&num_arr[index],sizeof(int),1,fp);
        if (feof(fp)){
            // printf("index:%d\n",index);
            end_arr[index] = 1;
            continue;
        }
        // printf("index:%d now_num:%d\n",index,num_arr[index]);
    }









    


   
    
    return 0;
}
