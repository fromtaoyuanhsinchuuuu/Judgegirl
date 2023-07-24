#include <stdio.h>
#include <stdbool.h>

int main()
{
    int W,D;
    scanf("%d%d",&W,&D);
    bool mirror[D][W];
    for (int i = 0 ; i < D ; i++){
        for (int j = 0 ; j < W ; j++){
            int x;
            scanf("%d",&x);
            mirror[i][j] = x;
        }
    }
    int total = (W+D)*2;
    int dir[total];  // 上:0,左:1,下:2,右:3
    for (int i = 0 ; i < W ; i++){
        dir[i] = 0;
        dir[i+D+W] = 2;
    }
    int j = 0;
    for (int i = W ; j < D ; i++){
        dir[i] = 1;
        dir[i+D+W] = 3;
        j += 1;
    }
    // for (int i = 0 ; i < 2*(W+D) ; i++){
    //     printf("%d:%d\n",i,dir[i]);
    // }
    # define up 0
    # define left 1
    # define down 2
    # define right 3
    for (int i = 0 ; i < total ; i++){
        int x,y;
        /* 初始化光徑位置 */
        switch (dir[i]){
            case up:
                x = i;
                y = D-1;
                break;
            case left:
                x = W-1;
                y = D-(i-W)-1;
                break;
            case down:
                x = W-1-(i-W-D);
                y = 0;
                break;
            case right:
                x = 0;
                y = i - (2*W + D);
                break;
        }
        /* 光開始移動 */
        int direction = dir[i];
        while (y >= 0 && x >= 0 && x <= W-1 && y <= D-1){
            // printf("i:%d row:%d col:%d direction:%d\n",i,y,x,direction);
            switch (direction)
            {
                case up:
                    if (mirror[y][x]){
                        // printf("mirror i:%d row:%d col:%d\n",i,y,x);
                        x++;
                        direction = right;
                    }
                    else{
                        y--;
                    }
                    break;
                case left:
                    if (mirror[y][x]){
                        // printf("row:%d col:%d\n",y,x);
                        // printf("i:%d row:%d col:%d\n",i,y,x);
                        // printf("mirror i:%d row:%d col:%d\n",i,y,x);
                        y++;
                        direction = down;
                    }
                    else{
                        x--;
                    }
                    break;
                case down:
                    if (mirror[y][x]){
                        // printf("row:%d col:%d\n",y,x);
                        // printf("i:%d row:%d col:%d\n",i,y,x);
                        // printf("mirror i:%d row:%d col:%d\n",i,y,x);

                        direction = left;
                        x--;
                    }
                    else{
                        y++;
                    }
                    break;
                case right:
                    if (mirror[y][x]){
                        // printf("row:%d col:%d\n",y,x);
                        // printf("i:%d row:%d col:%d\n",i,y,x);
                        // printf("mirror i:%d row:%d col:%d\n",i,y,x);

                        direction = up;
                        y--;
                    }
                    else{
                        x++;
                    }
                    break;
                default:
                    break;
            }
            // printf("i:%d row:%d col:%d direction:%d\n",i,y,x,direction);

        }
        // printf("i:%d final: row:%d col:%d\n",i,y,x);
        // printf("i:%d x_init:%d y_init:%d\n",i,x,y);
        if (x == W){
            printf("%d\n",D+W-y-1);
        }
        else if (x == -1){
            printf("%d\n",2*W+D+y);
        }
        else if (y == D){
            printf("%d\n",x);
        }
        else if (y == -1){
            printf("%d\n",2*W+D-1-x);
        }
        else{
            printf("dick");
        }
    }
    return 0;
}




    

