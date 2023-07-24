int eval(int exp[]);

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

// #include "eval.h"

int find_index(int *ptr[],int i,int dr)
{
    while (ptr[i] == NULL){
        i += dr;
    }
    return i;
}


 
int eval(int exp[]) {
    if (exp[0] == 1){
        return exp[1];
    }
    int *ptr[exp[0] + 1];
    ptr[0] = &exp[0];
    for (int i = 1; i <= exp[0]; i++){
        ptr[i] = &exp[i];
        if (i % 2 == 0 && !(exp[i] == 1 || exp[i] == 2 || exp[i] == 3 || exp[i] == 4)){
            return -2147483646;
        }
        else if (exp[i] == 4 && exp[i + 1] == 0){
            return -2147483647;
        }
    }
    int lastindex = 0;
    while (1){
        int index = -1;
        int mode = -1;
        for (int i = lastindex+1; i <= exp[0]; i++){
            if (ptr[i] != NULL && *ptr[i] == 3 && i % 2 == 0){
                mode = 3;
                index = i;
                break;
            }
            else if (ptr[i] != NULL && *ptr[i] == 4 && i % 2 == 0){
                mode = 4;
                index = i;
                break;
            }
        }

        // printf("index:%d\n",index);

        int prev_index = find_index(ptr,index-1,-1);
        int rear_index = find_index(ptr,index+1,1);

        

        if (mode == -1){
            break;
        }
        else{
            if (mode == 3){
                // printf("prev_index:%d\n",prev_index);
                // printf("behine_mul:%d\n",index+1);
                *ptr[index] = *ptr[prev_index] * *ptr[rear_index];
                lastindex = index;


                // printf("*ptr[%d]:%d\n",index,*ptr[index]);
            }
            else if (mode == 4){    
                *ptr[index] = *ptr[prev_index] / *ptr[rear_index];
                // printf("*ptr[%d]:%d\n",index,*ptr[index]);
                lastindex = index;

            }
            else{
                printf("error!!\n");
                return 0;
            }
            ptr[rear_index] = NULL;
            ptr[prev_index] = NULL;
        }
    }

    for (int i = 1; i <= exp[0]; i++){
            if (ptr[i] != NULL){
                // printf("*ptr[%d]:%d \n",i,*ptr[i]);
            }
    }
    int result = 0;
    int last_index = find_index(ptr,1,1);
    while (1){
        int index = -1;
        int mode = -1;
        for (int i = last_index + 1; i <= exp[0]; i++){
            if (ptr[i] != NULL && *ptr[i] == 1 && i % 2 == 0){
                index = i;
                mode = 1;
                break;
            }
            else if (ptr[i] != NULL && *ptr[i] == 2 && i % 2 == 0){
                index = i;
                mode = 2;
                break;
            }
        }
        int front_index = find_index(ptr,index+1,1);
        int rear_index = find_index(ptr,index-1,-1);
        // printf("front:%d\n",front_index);
        // printf("rear:%d\n",rear_index);
        if (mode == -1){
            return *ptr[last_index];
        }
        else if (mode == 1){
            *ptr[index] = *ptr[front_index] + *ptr[rear_index];
            last_index = index;
            // printf("result:%d\n",*ptr[last_index]);
        }
        else if (mode == 2){
            *ptr[index] = *ptr[rear_index] - *ptr[front_index];
            last_index = index;
            // printf("result:%d\n",*ptr[last_index]);

        }
        ptr[front_index] = NULL;
        ptr[rear_index] = NULL;
    }

    /* add your code */
}