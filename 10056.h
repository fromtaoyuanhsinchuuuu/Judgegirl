#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTR 32
#define MAXCOl 128
#define MAXN 300

typedef struct {
    char Name[MAXSTR];
    int score[MAXCOl];
} Person_data;

typedef struct {
    int dim_n;
    int person_num;
    Person_data Person_datas[MAXN];
} ExamTable;

void init(ExamTable *self, int n);
void addrow(ExamTable *self, char *name, int score[]);
void print(ExamTable *self, int order[]);
