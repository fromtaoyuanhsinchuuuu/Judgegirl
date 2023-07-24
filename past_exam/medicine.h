#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXNAME 128
#define MAXWEIGHT 5000
#define ACTIVE 2
#define INACTIVE 5

typedef struct weight_and_name{
    char Name[MAXNAME];
    int Weight;

} Weight_and_Name;

typedef struct medicine{

    int active_num;
    int inactive_num;
    char maxIngredient[MAXNAME];
    int maxWeight;
    int totalweight;
    Weight_and_Name active[ACTIVE];
    Weight_and_Name Inactive[INACTIVE];


} Medicine;

void init(Medicine *medicine);
int addActive(Medicine *medicine, char *name, int weight);
int addInactive(Medicine *medicine, char *name, int weight);
void print(Medicine *medicine);
int totalWeight(Medicine *medicine);
char *maxIngredient(Medicine *medicine);