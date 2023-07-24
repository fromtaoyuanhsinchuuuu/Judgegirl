#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

typedef unsigned long long int ull;

int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int in_the_shelf_and_index(int n,ull shelf)
{
    for (int shelf_index = 1; shelf_index <= 8; shelf_index++){
        if (shelf % 256 == n){
            return shelf_index;
        }
        else{
            shelf >>= 8;
        }
    }
    return 0;
}

ull take_book_and_push(int shelf_index,ull shelf)
{
    ull after_shelf_index = (shelf >> (shelf_index * 8)) << (shelf_index * 8);
    // printf("after_shelf:%llu\n",after_shelf_index);
    ull now_book = (shelf - after_shelf_index) >> ((shelf_index - 1) * 8);
    // printf("nowbook:%llu\n",now_book);
    ull before_shelf_index = shelf - after_shelf_index - (now_book << ((shelf_index - 1) * 8));
    shelf = after_shelf_index + now_book + (before_shelf_index << 8);

    return shelf;
}


int main() {
    int n;
    ull shelf = 0;
    while (ReadInt(&n)) {
        int shelf_index = in_the_shelf_and_index(n,shelf);
        // printf("nown:%d shelf_index:%d\n",n,shelf_index);
        assert (shelf_index >= 0 && shelf_index <= 8);
        if (shelf_index >= 1 && shelf_index <= 7){
            /* shelf_index是從1~8 */
            shelf = take_book_and_push(shelf_index,shelf);
        }
        else{
            shelf = (shelf << 8) + n;
        }
        // add your code
    }   
    int shelf_arr[8];
    for (int i = 0; i < 8; i++){
        shelf_arr[i] = shelf % 256;
        shelf >>= 8;
    }
    for (int i = 7; i >= 0; i--){
        printf("%d%c",shelf_arr[i]," \n"[i == 0]);
    } 
    // output your answer
    return 0;
}