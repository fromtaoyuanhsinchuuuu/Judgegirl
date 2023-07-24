#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXARR 2050
#define SET 0
#define NUM 1

typedef struct array {

    int arr[2][MAXARR];
    int left;
    int right;

} ARRAY;

void init(ARRAY *a,  int left, int right);
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a);

