#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXM 65536
#define MAXN 2147483647

#define R 0
#define U 1
#define L 2
#define D 3

#define DIR 4
 
typedef struct {
    int x, y;
} Attraction;

int abs(int a)
{
    return (a >= 0)? a: -a;
}

int min(int u, int l, int r, int d)
{
    int min = (u <= l)? u: l;
    min = (min <= r)? min: r;
    return (min <= d)? min: d;
}

int min_dir(Attraction pos, int N)
{
    int dir[DIR];

    dir[R] = pos.y;
    dir[U] = N - 1 - pos.x;
    dir[L] = N - 1 - pos.y;
    dir[D] = pos.x;

    int now_min = MAXN;
    int min_dir_index = -1;
    for (int i = 0; i < DIR; i++){
        if (dir[i] < now_min){
            now_min = dir[i];
            min_dir_index = i;
        }
    }

    return min_dir_index;
    
}

int dis(int coor, int N)
{
    if (N == 0){
        return coor;
    }
    return abs((N - 1) - coor);
}


bool swap(Attraction pos1, Attraction pos2, int N)
{
    int pos1_dir = min_dir(pos1,N);
    int pos2_dir = min_dir(pos2,N);

    if (pos1_dir > pos2_dir){
        return 1;
    }
    else if (pos1_dir == pos2_dir){
        if (pos1_dir == R && pos1.x > pos2.x){
            return 1;
        }
        else if (pos1_dir == U && pos1.y > pos2.y){
            return 1;
        }
        else if (pos1_dir == L && pos1.x < pos2.x){
            return 1;
        }
        else if (pos1_dir == D && pos1.y > pos2.y){
            return 1;
        }
    }

    return 0;

}

int bubble_sort(Attraction pos[],int M,int N)
{
    for (int i = 0; i < M; i++){
        for (int j = 0; j < M - 1; j++){
            int ret = min(abs(pos[j].x - (N - 1)),abs(pos[j].x),abs(pos[j].y - (N - 1)),abs(pos[j].y)) - min(abs(pos[j + 1].x - (N - 1)),abs(pos[j + 1].x),abs(pos[j + 1].y - (N - 1)),abs(pos[j + 1].y));
            if (ret > 0 || ret == 0 && swap(pos[j],pos[j + 1],N)){
                // printf("swap! pos[j] = (%d,%d), pos[j + 1] = (%d,%d) ret = %d\n",pos[j].x,pos[j].y,pos[j + 1].x,pos[j + 1].y,ret);
                Attraction temp = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1],"r");
    assert(fp != NULL);

    int N,M;
    scanf("%d%d",&N,&M);

    Attraction pos[MAXM];
    for (int i = 0; i < M; i++){
        fread(pos + i, sizeof(Attraction), 1, fp);
    }

    bubble_sort(pos, M, N);
    for (int i = 0; i < M; i++){
        printf("%d %d\n",pos[i].x,pos[i].y);
    }
    
    return 0;
}
