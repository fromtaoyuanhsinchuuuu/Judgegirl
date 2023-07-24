#include <stdio.h>
#define Maxsize 150
#define green 0
#define blue 1

int main(void)
{
    static int matrix[100][100][100];
    int N,M;
    // printf("KJDSALKSA\n");
    scanf("%d%d",&N,&M);
    // printf("KJDSALKSA");
    int num = 0;
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            for (int k = 0 ; k < N ; k++, num++){
                matrix[i][j][k] = num;
            }
        }
    }
    for (int i = 0 ; i < M ; i++){
        int rotate,index;
        scanf("%d%d",&rotate,&index);
        int temp[Maxsize][Maxsize];
        switch (rotate)
        {
            case blue:
                for (int i = 0 ; i < N ; i++){
                    for (int j = 0 ; j < N ; j++){
                        temp[i][j] = matrix[j][i][index];
                    }
                }
                for (int i = 0 ; i < N ; i++){
                    for (int j = 0 ; j < N ; j++){
                        matrix[i][j][index] = temp[i][N-1-j];
                    }
                } 
                break;
            case green:
                for (int i = 0 ; i < N ; i++){
                    for (int j = 0 ; j < N ; j++){
                        temp[i][j] = matrix[index][j][i];
                    }
                }
                for (int i = 0 ; i < N ; i++){
                    for (int j = 0 ; j < N ; j++){
                        matrix[index][i][j] = temp[i][N-1-j];
                    }
                } 
                break;
        }
    }
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            for (int k = 0 ; k < N ; k++){
                printf("%d ",matrix[i][j][k]);
            }
            printf("\n");
        }
    }
    
    return 0;
}

