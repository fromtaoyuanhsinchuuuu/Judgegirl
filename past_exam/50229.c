#include <stdio.h>
 
int main(void){
    int k;
    scanf("%d",&k);
    int cup_V[20000];
    for (int i = 0 ; i < k ; i++){
        scanf("%d",&cup_V[i]);
    }
    int water_V[20000];
    for (int i = 0 ; i < k ; i++){
        scanf("%d",&water_V[i]);
    }
    int i,j;
    while (scanf("%d%d",&i,&j) != EOF){
        if (i == k){
            water_V[j] = cup_V[j];
        }
        if (j == k){
            water_V[i] = 0;
        }
        if (i != k && j != k){
            while (water_V[i] != 0 && water_V[j] != cup_V[j]){
                water_V[i]--;
                water_V[j]++;
            }
        }
    }
    for (int i = 0 ; i < k ; i++){
        printf("%d ",water_V[i]);
    }
    return 0;
}