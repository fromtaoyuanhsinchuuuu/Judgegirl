#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXF 1000
#define MAXL 1500
#define LIMIT 4
 
struct Elevator {
    int nowfloor;
    int arrived_floor[MAXL];
    int F;
    int u;
    int d;
    int u_consecutive_count;
    int d_consecutive_count;
    int count;
};
typedef struct Elevator Elevator;

Elevator* newElevator(int u, int d, int F)
{
    Elevator *newelvator = (Elevator *) malloc(sizeof(Elevator));
    newelvator->arrived_floor[0] = 1;
    newelvator->count = 1;
    newelvator->d = d;
    newelvator->F = F;
    newelvator->u = u;
    newelvator->d_consecutive_count = 0;
    newelvator->u_consecutive_count = 0;
    newelvator->nowfloor = 1;
    return newelvator;
}
int up(Elevator* elevator)
{
    elevator->d_consecutive_count = 0;
    if (elevator->nowfloor + elevator->u <= elevator->F){
        elevator->nowfloor += elevator->u;
        elevator->arrived_floor[(elevator->count)++] = elevator->nowfloor;
        return 1;
    }
    else{
        (elevator->u_consecutive_count)++;
        if (elevator->u_consecutive_count == LIMIT){
            return -1;
        }
    }
    return 0;
}
int down(Elevator* elevator)
{
    elevator->u_consecutive_count = 0;
    if (elevator->nowfloor - elevator->d >= 1){
        elevator->nowfloor -= elevator->d;
        elevator->arrived_floor[(elevator->count)++] = elevator->nowfloor;
        return 1;
    }
    else{
        (elevator->d_consecutive_count)++;
        if (elevator->d_consecutive_count == LIMIT){
            return -1;
        }
    }
    return 0;
}
int visited(Elevator* elevator, int floor)
{
    for (int i = 0; i < elevator->count; i++){
        if (floor == elevator->arrived_floor[i]){
            return 1;
        }
    }
    return 0;
}
int getPosition(Elevator* elevator)
{
    return elevator->nowfloor;
}

int main(){
    int N;
    scanf("%d",&N);

    int u,d,F;
    char cmds[MAXL];
    for (int i = 0; i < N; i++){
        scanf("%d%d%d%s",&u,&d,&F,cmds);
        Elevator* elevator = newElevator(u,d,F);
        int cmd_len = strlen(cmds);
        for (int i = 0; i < cmd_len; i++){
            int return_num = 0;
            if (cmds[i] == 'U'){
                return_num = up(elevator);
            }
            else if (cmds[i] == 'D'){
                return_num = down(elevator);
            }
            else{
                assert(0);
            }
            if (return_num == 1){
                printf("Valid %d\n",getPosition(elevator));
            }
            else if (return_num == 0){
                printf("Invalid\n");
            }
            else{
                assert(return_num == -1);
                printf("Broken\n");
                break;
            }
        }
        for (int floor = 1; floor <= F; floor++){
            if (visited(elevator,floor)){
                printf("%d\n",floor);
            }
        }
        free(elevator);
    }
}
