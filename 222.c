#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

typedef unsigned long long int ull;


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



int main(void)
{ 
    int n;
    ull shelf = 0;

    while (scanf("%d",&n) != EOF){
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
        // printf("now_n:%d shelf:%llu\n",n,shelf);
    }
    // printf("%llu",shelf);
    int shelf_arr[8];
    for (int i = 0; i < 8; i++){
        shelf_arr[i] = shelf % 256;
        shelf >>= 8;
    }
    for (int i = 7; i >= 0; i--){
        printf("%d%c",shelf_arr[i]," \n"[i == 0]);
    }
    
    return 0;
}
