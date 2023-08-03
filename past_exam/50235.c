#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define MAXSTR 21
#define MAX 1001
#define C 3

typedef struct Hash_table{
    int num;
    char str[MAXSTR];
    int prev_index;
    int ans_Index;
} Hash_table;

int hash_num = 0;
int ansIndex = 0;

Hash_table hash_table[MAX][C];

void insert(char *str)
{
    for (int i = 0; i < C; i++){
        if (hash_table[hash_num][i].num == 0){
            strcpy(hash_table[hash_num][i].str, str);
            hash_table[hash_num][i].num = 1;
            printf("%s %d\n", str, 1);
            return;
        }
        else if (strcmp(hash_table[hash_num][i].str, str)) continue;
        hash_table[hash_num][i].num++;
        printf("%s %d\n", str, hash_table[hash_num][i].num);
        return;
    }
    return;
}

int cal(char *str)
{    
    int len = strlen(str), hash = 0;
    for (int i = 0; i < len; i++){
        if (!(isalnum(str[i]) || str[i] == '_')) return -1;
        if (i == 0 && isdigit(str[i])) return -1;
        hash += str[i];
        hash %= 1000;
    }
    return hash;
}

int main(void)
{
    char str[MAXSTR];
    while (scanf("%s", str) != EOF){
        hash_num = cal(str);
        if (hash_num == -1) continue;
        insert(str);
    }
    return 0;
}
