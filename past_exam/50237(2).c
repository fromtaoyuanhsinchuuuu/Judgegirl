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
    char *str;
} Data;

static char tower[MAXN][MAXN][MAXN][MAXSTR];

int z_Index[MAXN * MAXN] = {};

Data hash_table[MAXN * MAXN][C];
int ansIndex1 = -1, ansIndex2 = -1, K = -1;
char ansSTR[] = {'\0'};

int hash_func(char *str, int K, int len)
{

    int hash_num = 0;
    for (int i = 0; i < len; i++){
        hash_num *= 29;
        hash_num %= K;
        hash_num += (str[i] - hash_modify);
        hash_num %= K;
    }
    return hash_num;
}

int InsertToHashtable(char *str, int index)
{
    int len = strlen(str);
    int hashIndex = hash_func(str, K, len);

    int insertIndex = -1;
    for (int i = 0; i < C; i++){
        if (hash_table[hashIndex][i].num == 0) insertIndex = i;
        else if (!strcmp(hash_table[hashIndex][i].str, str)){
            ansIndex1 = index;
            ansIndex2 = hash_table[hashIndex][i].index;
            printf("%s\n", str);
            hash_table[hashIndex][i].num = 0;
            return 1;
        }
    }
    hash_table[hashIndex][insertIndex].str = str;
    hash_table[hashIndex][insertIndex].num = 1;
    hash_table[hashIndex][insertIndex].index = index;
    return 0;
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

    while(1){
        if (ansIndex1 == -1 || ansIndex2 == -1) break;
        int prev_ansIndex1 = ansIndex1, prev_ansIndex2 = ansIndex2;
        z_Index[ansIndex1]++, z_Index[ansIndex2]++;
        int row1 = ansIndex1 / N, col1 = ansIndex1 % N;
        int row2 = ansIndex2 / N, col2 = ansIndex2 % N;

        ansIndex1 = -1, ansIndex2 = -1;
        if (z_Index[prev_ansIndex1] < N){
            InsertToHashtable(tower[row1][col1][z_Index[prev_ansIndex1]], prev_ansIndex1);
        }
        if (z_Index[prev_ansIndex2] < N){
            InsertToHashtable(tower[row2][col2][z_Index[prev_ansIndex2]], prev_ansIndex2);
        }
    }
    return 0;
}
