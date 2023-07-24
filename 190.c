#include <stdio.h>

int f(int x,int y)
{
    return (4*x-6*y);
}

int evaluate_f(int *iptr[], int n, int *index)
{
    int max = -100000;
    *index = 1000000;
    // printf("%d",*(iptr[0]+1));
    for (int i = 0; i < n ; i++){
        int nownum = f(*iptr[i],*(iptr[i]+1));
        if (nownum > max || nownum == max && i < *index ){
            max = nownum;
            *index = i;
            // printf("ads");
        }
        // printf("nownum=%d\n",nownum);
    }
    return max;

}

// #include "evaluate_f.h"
int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}