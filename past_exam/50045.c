#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define X 0
#define Y 1
#define Z 2

void move(int position[3],int command)
{
    switch (command)
    {
        case 1:
            position[X]++;
            break;
        case 2:
            position[X]--;
            break;
        case 3:
            position[Y]++;
            break;
        case 4:
            position[Y]--;
            break;
        case 5:
            position[Z]++;
            break;
        case 6:
            position[Z]--;
            break;
        default:
            break;
    }
    return;
}

int abs(int a)
{
    return (a >= 0)? a: -a;
}

int distance(int position1[3],int position2[3])
{
    return (abs(position1[X] - position2[X]) + abs(position1[Y] - position2[Y]) + abs (position1[Z] - position2[Z]));
}

// bool explode()

int main(void)
{
    int position[3];
    scanf("%d%d%d",&position[X],&position[Y],&position[Z]);

    int mine[3];
    scanf("%d%d%d",&mine[X],&mine[Y],&mine[Z]);

    int blackhole[3];
    scanf("%d%d%d",&blackhole[X],&blackhole[Y],&blackhole[Z]);

    int N;
    scanf("%d",&N);

    int command;
    int cont = 1;
    int blackhole_exist = 1;
    for (int i = 0; i < N && cont; i++){
        scanf("%d",&command);
        move(position,command);
        // for (int j = 0; j < 5 && cont; j++){
        if (distance(position,mine) < 10){
            cont = 0;
        }
        else if (distance(position,blackhole) < 10 && blackhole_exist){
            position[X] = blackhole[X];
            position[Y] = blackhole[Y];
            position[Z] = blackhole[Z];
            blackhole_exist = 0;
        }
        
        if (i % 5 == 4 && cont){
            printf("%d %d %d\n",position[X],position[Y],position[Z]);
        }
    }
    
    return 0;
}
