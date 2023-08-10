#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 105
#define MAXSTR 6
#define C 10
#define hash_modify 96

typedef struct {
    int num;
    int index;
    char str[MAXSTR];
} Data;

static char tower[MAXN][MAXN][MAXN][MAXSTR];

int z_Index[MAXN * MAXN] = {};

Data hash_table[MAXN * MAXN][C];
int ansIndex1 = -1, ansIndex2 = -1, K = -1;
char ansSTR[] = {'\0'};


void init()
{
    for (int i  = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            for (int k = 0; k < C; k++){
                hash_table[i * MAXN + j][k].num = 0;
            }
        }
    }
}

int hash_func(char *str, int K, int len)
{

    int hash_num = 0;
    for (int i = 0; i < len; i++){
        hash_num += (str[0] - hash_modify);
        hash_num %= K;
        hash_num *= 29;
    }
    return hash_num;
}

void InsertToHashtable(char *str, int index)
{
    int len = strlen(str);
    int hashIndex = hash_func(str, K, len);

    for (int i = 0; i < C; i++){
        if (hash_table[hashIndex][i].num == 0){
            for (int j = 0; j < len; j++){
                hash_table[hashIndex][i].str[j] = str[j];
            }
            strcpy(hash_table[hashIndex][i].str, str);
            hash_table[hashIndex][i].num = 1;
            hash_table[hashIndex][i].index = index;
            return;
        }
        else if (!strcmp(hash_table[hashIndex][i].str, str)){
            ansIndex1 = index;
            ansIndex2 = hash_table[hashIndex][i].index;
            strcpy(ansSTR, str);
            hash_table[hashIndex][i].num = 0;
            return;
        }
    }
    return;
}

void getTower(int N)
{
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            for (int k = 0; k <= i; k++){
                scanf("%s", tower[j][k][i]);
                if (k == i || j == i){
                    InsertToHashtable(tower[j][k][i], j * N + k);
                    z_Index[j * N + k] = i;
                }
            }
        }
    }
    return;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    K = N * N;

    getTower(N);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d%c", z_Index[i * N + j], " \n"[j == N - 1]);
        }
    }

    printf("%s\n", ansSTR);


    while(1){
        // printf("Index1:%d, Index2:%d\n", ansIndex1, ansIndex2);
        if (ansIndex1 == -1 || ansIndex2 == -1) break;
        int prev_ansIndex1 = ansIndex1, prev_ansIndex2 = ansIndex2;
        printf("%s\n", ansSTR);
        // printf("ansSTR:%s\n", ansSTR);
        z_Index[ansIndex1]++, z_Index[ansIndex2]++;
        int row1 = ansIndex1 / N, col1 = ansIndex1 % N;
        int row2 = ansIndex2 / N, col2 = ansIndex2 % N;
        // printf("(%d,%d,%d)\n", row2, col2, z_Index[prev_ansIndex2]);

        ansIndex1 = -1, ansIndex2 = -1;
        if (z_Index[prev_ansIndex1] < N){
            // printf("str1:insert %s\n", tower[row1][col1][z_Index[prev_ansIndex1]]);
            InsertToHashtable(tower[row1][col1][z_Index[prev_ansIndex1]], prev_ansIndex1);
        }
        if (z_Index[prev_ansIndex2] < N){
            // printf("(%d,%d,%d)\n", row2, col2, z_Index[prev_ansIndex2]);
            // printf("str2:insert %s\n", tower[row2][col2][z_Index[prev_ansIndex2]]);
            InsertToHashtable(tower[row2][col2][z_Index[prev_ansIndex2]], prev_ansIndex2);
        }
    }
    
    return 0;
}
