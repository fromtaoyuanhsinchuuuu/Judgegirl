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