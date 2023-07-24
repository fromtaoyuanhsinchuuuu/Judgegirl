#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100

typedef struct{
    int x, y;
    int g;
} CarStatus;
 
typedef struct{
    int t, v;
} Command;
 
typedef struct{
    int num;
    CarStatus status[MAXN];
} CarStatusList;
 
CarStatusList carSimulation(CarStatus car, Command commands[])
{
    CarStatusList car_list;
    car_list.num = 0;
    for (int i = 0; i < MAXN; i++){
        int nowt = commands[i].t,nowv = commands[i].v;
        if (nowt != 1 && nowt != 0 && (car.g - nowv) < 0){
            return car_list;
        }
        if (nowt == 0){
            // car_list.num++;
            return car_list;
        }
        else if (nowt == 1){
            car.g += nowv;
            continue;
        }
        else if (nowt == 2){
            car.x += nowv;
        }
        else if (nowt == 3){
            car.x -= nowv;
        }
        else if (nowt == 4){
            car.y += nowv;
        }
        else if (nowt == 5){
            car.y -= nowv;
        }
        else{
            return car_list;
        }
        car.g -= nowv;
        assert(car.g >= 0);
        car_list.status[car_list.num] = car;
        car_list.num++;

    }

    return car_list;
}

int main(){
    int N;
    CarStatus car;
    Command commands[MAXN];
 
    assert(scanf("%d%d%d", &car.x, &car.y, &car.g) == 3);
    assert(scanf("%d", &N) == 1);
    for(int i = 0; i < N; i++)
        assert(scanf("%d%d", &commands[i].t, &commands[i].v) == 2);
 
    CarStatusList result= carSimulation(car, commands);
 
    for(int i = 0; i < result.num; i++)
        printf("%d %d %d\n", result.status[i].x, result.status[i].y, result.status[i].g);
 
    return 0;
}
