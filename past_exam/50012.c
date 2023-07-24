#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef unsigned long long int ull;

void printBlock(unsigned long long int *block) {
    ull Block = *block;
    int board[8][8];
    for (int i = 0; i < 64; i++){
        if (Block & 1 == 1){
            board[i % 8][i / 8] = 1;
        }
        else{
            board[i % 8][i / 8] = 0;
        }
        Block >>= 1;
    }
    for (int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            printf("%d%c",board[r][c]," \n"[c == 7]);
        }
    }

}
 
void initialize(unsigned long long int *block, int row, int column, int size) {
    ull Block = 0;
    ull left_upper_corner = 1;  
    left_upper_corner <<= row * 8 + column;
    // printf("%d",row * 8 + column);
    // printf("%llu",left_upper_corner);
    Block += left_upper_corner;
    for (int i = 1; i < size; i++){
        ull adder = left_upper_corner << i;
        Block += adder;
    }
    ull upper = Block;
    for (int i = 1; i < size; i++){
        ull adder = upper << (i * 8);
        Block += adder;
    }
    *block = Block;
}
 
int moveLeft(unsigned long long int *block) {
    ull adder = 1;
    ull check_num = 1;
    for (int i = 1; i < 8; i++){
        check_num += (adder << (i * 8));
    }
    // printBlock(&check_num);
    if ((check_num & *block) != 0){
        return 0;
    }
    *block >>= 1;
    return 1;
}
 
int moveRight(unsigned long long int *block) {
    ull adder = (1 << 7);
    ull check_num = adder;
    for (int i = 1; i < 8; i++){
        check_num += (adder << i * 8);
    }
    ull dick = check_num & *block;
    if ((check_num & *block) != 0){
        return 0;
    }
    *block <<= 1;
    return 1;
}
 
int moveUp(unsigned long long int *block) {
    ull check_num = 255;
    if ((check_num & *block) != 0){
        return 0;
    }
    *block >>= 8;
    return 1;
}
 
int moveDown(unsigned long long int *block) {
    // your implementation here   
    ull check_num = (ull)255;
    check_num <<= 56;
    if ((check_num & *block) != 0){
        return 0;
    }
    *block <<= 8;
    return 1;

}

int main() {
    unsigned long long int num;
    char operation;
    int ret;
 
    scanf("%llu", &num);
 
    while (1) {
        ret = 1;
 
        scanf("%c", &operation);
 
        if (operation == 'p') {
            printBlock(&num);
            // break;
        } else if (operation == 'u')
            ret = moveUp(&num);
        else if (operation == 'd')
            ret = moveDown(&num);
        else if (operation == 'l')
            ret = moveLeft(&num);
        else if (operation == 'r')
            ret = moveRight(&num);
        else if (operation == 'i') {
            int row, column, size;
            scanf("%d %d %d", &row, &column, &size);
            initialize(&num, row, column, size);
        }
 
        if (ret == 0)
            printf("Invalid move!\n");
    }
 
    return 0;
}