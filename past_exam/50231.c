#include <stdio.h>
#include <stdbool.h>

// bool hash_table(i,j,k,)

int main(void){
    int N,S,C;
    scanf("%d%d%d",&N,&S,&C);
    static int tower[105][105][105];
    bool expose[105][105][105] = {0};
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j <= i ; j++){
            for (int k = 0 ; k <= i ; k++){
                scanf("%d",&tower[i][j][k]);
                if (k == i || j == i){
                    expose[i][j][k] = 1;
                }
            }
        }
    }

    // printf("\n");
    // for (int i = 0 ; i < N ; i++){
    //     for (int j = 0 ; j <= i ; j++){
    //         for (int k = 0 ; k <= i ; k++){
    //             printf("%d ",expose[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    // }  

  
    int hash_table[S][C];

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j <= i ; j++){
            for (int k = 0; k <= i ; k++){
                if (expose[i][j][k] == 1){
                    int num = tower[i][j][k];
                    int S_index = (77*num+2222)%S;
                    

                }
            }
        }
    }

    int time = 0;
    
    while (time < 100){
        time++;
        for (int i = 0 ; i < N ; i++){
            for (int j = 0 ; j < N ; j++){
                for (int k = 0 ; k < N ; k++){
                    int nownumber = tower[i][j][k];
                    if (nownumber != 0 && expose[i][j][k] == 1){
                        for (int z = 0 ; z < N ; z++){
                            for (int y = 0 ; y < N ; y++){
                                for (int x = 0 ; x < N ; x++){
                                    if (tower[z][y][x] == nownumber && expose[z][y][x] == 1 && !(z == i && y == j && x == k)){
                                        // printf("nownnumber:%d\n",nownumber);
                                        tower[z][y][x] = 0;
                                        tower[i][j][k] = 0;
                                        expose[z+1][y][x] = 1;
                                        expose[i+1][j][k] = 1;
                                        printf("%d ",nownumber);
                                    }

                                }
                            }
                        }
                    }

                }
            }
        }
    }
    return 0;
}