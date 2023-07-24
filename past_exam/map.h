#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSTRING 128
#define MAXSIZE 1024

typedef struct Key_Val{
    int key;
    char val[MAXSTRING];
} Key_Val;

typedef struct map{
    int size;
    Key_Val pairARR[MAXSIZE];
} Map;

void init(Map *map);
int map(Map *map, const int key, const char *value);
int numPairs(Map *map);
void print(Map *map);
const char *getValue(Map *map, const int key);
int unmap(Map *map, int key);
int reverseMap(Map *map, const char *value, int keys[]);
