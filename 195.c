#include <stdio.h>
#include <stdbool.h>

bool win_or_not(int matrix[3][3],int now_turn)
{
    bool win = 0;
    for (int row = 0 ; row < 3 ; row++){
        for (int col = 0 ; col < 3 ; col++){ /* 掃橫的 */
            if (matrix[row][col] != now_turn){
                break;
            }
            else if (matrix[row][col] == now_turn && col == 2){
                // printf("dick\n");
                win = 1;
                return win;
            }
        }
    }
    for (int col = 0 ; col < 3 ; col++){
        for (int row = 0 ; row < 3 ; row++){ /* 掃直的 */
            if (matrix[row][col] != now_turn){
                break;
            }
            else if (matrix[row][col] == now_turn && row == 2){
                // printf("dick\n");
                win = 1;
                return win;
            }
        }
    }
    if ((matrix[0][0] == matrix[1][1]) && (matrix[1][1] == matrix[2][2]) && (matrix[0][0] == now_turn) || (matrix[0][2] == matrix[1][1]) && (matrix[2][0] == matrix[1][1]) && (matrix[1][1] == now_turn)){
                // printf("dick\n");

        win = 1;
        return win;
    }
    return win;
}

int main(void)
{
    int N;
    scanf("%d",&N);
    int matrix[3][3] = {}; /* 1表黑子,-1表白子 */
    int r;
    int c;
    int now_turn = 1;
    bool draw = 1;
    for (int i = 0 ; i < N ; i++){
        scanf("%d%d",&r,&c);
        if (!(r >= 3 || r < 0 || c >= 3 || c < 0 || matrix[r][c])){
            if (now_turn == 1){
                matrix[r][c] = now_turn;
                if (win_or_not(matrix,now_turn)){
                    printf("Black wins.\n");
                    draw = 0;
                    break;
                }
                now_turn = -1;
            }
            else if (now_turn == -1){
                matrix[r][c] = now_turn;
                 if (win_or_not(matrix,now_turn)){
                    printf("White wins.\n");
                    draw = 0;
                    break;
                }
                now_turn = 1;
            }
        }
        else{
            continue;
        }
    }
    if (draw){
        printf("There is a draw.");
    }
    return 0;
}
