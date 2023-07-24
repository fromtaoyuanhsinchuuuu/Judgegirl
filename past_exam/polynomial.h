#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXTERM 4096



typedef struct polynomial{
    
    int term_num;
    int coefficient[MAXTERM];


} Polynomial;

 
void init(Polynomial *poly, int coefficient[], int n);
Polynomial add(Polynomial *poly1, Polynomial *poly2);
Polynomial multiply(Polynomial *poly1, Polynomial *poly2);
void print(Polynomial *poly);

