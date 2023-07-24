#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1024
#define MAXNAME 12

typedef unsigned long long ull;

typedef struct 
{
    char name[MAXNAME];
    int W;
} Data;

int cmp(const void *a, const void *b)
{
    Data *ptr1 = (Data *)a;
    Data *ptr2 = (Data *)b;

    if (ptr1->W - ptr2->W != 0){
        return (ptr1->W - ptr2->W);
    }

    else {
        return strcmp(ptr1->name, ptr2->name);
    }
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "rb");
    assert(fp != NULL);

    Data data_arr[MAXN];
    int n = 0;
    while (!feof(fp)){
        fread(&data_arr[n], sizeof(Data), 1, fp);
        n++;
    }

    n--;
    qsort(data_arr, n, sizeof(Data), cmp);

    // for (int i = 0; i < n; i++){
    //     printf("%s %d\n",data_arr[i].name, data_arr[i].W);
    // }

    ull median_W;

    int max_index = n - 1;

    int max_W = data_arr[n - 1].W;
    for (; max_index > 0; max_index--){
        if (data_arr[max_index - 1].W != max_W){
            break;
        }
    }

    int bucket_arr[MAXN] = {};

    int bucket_index = 0;
    int prev_buc = data_arr[0].W / 1000;
    for (int i = 0; i < n; i++){
        if (data_arr[i].W / 1000 == prev_buc){
            bucket_arr[bucket_index]++;
            
        }
        else{
            bucket_arr[++bucket_index]++;
            prev_buc = data_arr[i].W / 1000;
        }
    }

    for (int i = 0; i <= bucket_index; i++){
        printf("%d\n",bucket_arr[i]);
    }




    if (n % 2 == 0){
        median_W = (data_arr[n / 2].W + data_arr[n / 2 - 1].W) / 2;
    }

    else {
        median_W = data_arr[n / 2].W;
    }
    printf("%s\n%s\n%llu\n",data_arr[0].name, data_arr[max_index].name,median_W);
    


    return 0;
}

