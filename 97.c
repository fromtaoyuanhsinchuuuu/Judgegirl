#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int parking_lots[n][3];
    for (int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < 3 ; j++){
            int k;
            scanf ("%d",&k);
            parking_lots[i][j] = k;     
            // printf("parking_lots[%d][%d]=%d\n",i,j,k)  ;
            }
    }
    int m;
    scanf("%d",&m);
    int bicycle[m][2];
    for ( int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < 2 ; j++){
            int k;
            scanf("%d",&k);
            bicycle[i][j] = k;
        }
    }
    // n=停車場數 m=腳踏車數
    int distance[n][m];
    for (int j = 0 ; j < m ; j++){
        for (int i = 0 ; i < n ; i++){
            distance[i][j] = 0;
            distance[i][j] += (bicycle[j][0]-parking_lots[i][0]>0)?bicycle[j][0]-parking_lots[i][0]:-(bicycle[j][0]-parking_lots[i][0]);
            distance[i][j] += (bicycle[j][1]-parking_lots[i][1]>0)?bicycle[j][1]-parking_lots[i][1]:-(bicycle[j][1]-parking_lots[i][1]);
            // printf("\ndistance[%d][%d]:%d",i,j,distance[i][j]);
        }
    // distance[i][j] = 編號j的腳踏車對編號i的停車場的距離
    }
    int parking_num[n];
    for (int i = 0 ; i < n ; i++){
        parking_num[i] = 0;
    }
    int nearest_distance;
    int nearest_parking_lot;
    for (int j = 0 ; j < m ; j++){
        nearest_parking_lot = 0;
        nearest_distance = distance[0][j];
        for (int i = 0 ; i < n ; i++){
            // printf("\nparking_lots[%d]:%d parking_num[%d]:%d",i,parking_lots[i][2],i,parking_num[i]);
            if ((distance[i][j] < nearest_distance || parking_lots[nearest_parking_lot][2] == parking_num[nearest_parking_lot])  && parking_lots[i][2] > parking_num[i]){
                nearest_distance = distance[i][j];
                nearest_parking_lot = i;
                // printf("\nnerest_parking_lot:%d",i);
            }
            else if (nearest_distance == distance[i][j] ){
                if (parking_lots[i][0] < parking_lots[nearest_parking_lot][0] && parking_num[i] < parking_lots[i][2]){
                    nearest_parking_lot = i;
                }
                else if (parking_lots[i][0] == parking_lots[nearest_parking_lot][0]){
                    if (parking_lots[i][1] <= parking_lots[nearest_parking_lot][1] && parking_num[i] < parking_lots[i][2]){
                        nearest_parking_lot = i;
                    }
                }
            }
        }
        // printf("\nnearest_parking_lot:%d",nearest_parking_lot);
        parking_num[nearest_parking_lot] += 1;
    }
    for (int i = 0 ; i < n ; i++){
        printf("%d\n",parking_num[i]);
    }
    return 0;
}
