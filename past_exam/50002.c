#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define Maxsize 100

int main()
{
    int n,k;                         
    scanf("%d%d",&n,&k);
    assert(n >= 1 && n <= 100 && k >= 0);
    bool life[2][Maxsize][Maxsize]; // life[0][n][n]表舊的，life[1][n][n]表新的
    for (int i = 0 ; i < n ; i++){
        // printf("k:%d\n",k);
        for (int j = 0 ; j < n ; j++){
            int x; // c的bool不能拿來被輸入，要用int宣告
            scanf("%d",&x);
            life[0][i][j] = x;
            // printf("life[0][%d][%d]:%d\n",i,j,life[0][i][j]);
        }
    }
    // printf("\n");
    // printf("life[0][0][2]:%d",life[0][0][2]);
    /*for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            printf("life[0][%d][%d]:%d\n",i,j,life[0][i][j]);
        }
    }*/
    int lifespan[n][n];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (life[0][i][j]){
                lifespan[i][j] = 1;
            }
            else{
                lifespan[i][j] = 0;
            }
        }
    }
    
    for (int times = 0 ; times < k ; times++){
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                int neighbor = 0;
                for (int dy = -1 ; dy < 2 ; dy++){
                    for (int dx = -1 ; dx < 2 ; dx++){
                        if ((!(dx == 0 && dy == 0)) && i+dy <= n-1 && j+dx <= n-1 && i+dy >= 0 && j+dx >= 0){
                            // printf("i:%d j:%d dy:%d dx:%d\n",i,j,dy,dx);
                            if (life[0][i+dy][j+dx]){
                                // printf("now_position:(%d,%d) neighbor:(%d,%d)\n",i,j,i+dy,j+dx);
                                neighbor++;
                            }
                        }
                    }
                }
                // printf("i:%d j:%d neightbor:%d\n",i,j,neighbor);
                if (life[0][i][j]){
                    if (neighbor == 2 || neighbor == 3){
                        life[1][i][j] = 1;
                        lifespan[i][j]++;
                    }
                    else{
                        life[1][i][j] = 0;
                    }
                }
                else{
                    if (neighbor == 3){
                        life[1][i][j] = 1;
                        lifespan[i][j]++;
                    }
                    else{
                        life[1][i][j] = 0;
                    }
                }
            }
        }
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                life[0][i][j] = life[1][i][j];
            }
        }
    }   
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (j != n-1){
                printf ("%d ",life[0][i][j]);
            }
            else{
                printf ("%d",life[0][i][j]);

            }
        }
        printf("\n");
    }
    int maxlife_span_i = 0;
    int maxlife_span_j = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            // printf("lifespan[%d][%d]:%d\n",i,j,lifespan[i][j]);
            if (lifespan[i][j] > lifespan[maxlife_span_i][maxlife_span_j] || lifespan[i][j] == lifespan[maxlife_span_i][maxlife_span_j] && i > maxlife_span_i ||  lifespan[i][j] == lifespan[maxlife_span_i][maxlife_span_j] && i == maxlife_span_i && j > maxlife_span_j){
                // printf("i:%d j:%d\n",i,j);
                maxlife_span_i = i;
                maxlife_span_j = j;
            }
        }
    }
    printf("%d %d",maxlife_span_i+1,maxlife_span_j+1);
    return 0;
}
