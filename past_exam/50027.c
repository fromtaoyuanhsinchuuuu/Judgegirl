#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define FileName 100
#define MAXNUM 1024

typedef struct {
    int balance;
    char name[128];
    int gender;
} Account;

void bubble_sort(Account data_arr[],int data_num)
{
    for (int i = 0; i < data_num; i++){
        for (int j = 0; j < data_num - 1; j++){
            if (strcmp(data_arr[j].name,data_arr[j+1].name) > 0){
                Account temp = data_arr[j];
                data_arr[j] = data_arr[j+1];
                data_arr[j+1] = temp;
            }
        }
    }
    return;
    
}

bool valid(Account data)
{
    if (data.balance < 0 || !(data.gender == 0 || data.gender == 1)){
        return 0;
    }
    int len = strlen(data.name);
    for (int i = 0; i < len; i++){
        if (data.name[i] != 32 && !isalpha(data.name[i])){
            return 0;
        }
    }
    return 1;
}


int main()
{

    char inputFile[FILENAME_MAX];
    char outputFile[FILENAME_MAX];
    Account data_arr[MAXNUM];
    int invalid_arr[MAXNUM] = {};
    int data_num = 0;
    scanf("%s%s",inputFile,outputFile);
    FILE *fp1 = fopen(inputFile,"rb");
    assert(fp1 != NULL);
    FILE *fp2 = fopen(outputFile,"wb");
    assert(fp2 != NULL);
    while (fread(&(data_arr[data_num]),sizeof(Account),1,fp1) == 1){
        data_num++;
    }
    // printf("%s %s",data_arr[0].name,data_arr[1].name);
    bubble_sort(data_arr,data_num);
    for (int i = 0; i < data_num; i++){
        if (valid(data_arr[i])){
            fwrite(&(data_arr[i]),sizeof(Account),1,fp2);
        }
    }
    return 0;
}