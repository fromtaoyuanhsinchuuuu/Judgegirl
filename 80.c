#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        int x1,y1,x2,y2,x3,y3;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        int a_square = (x2-x3)*(x2-x3) + (y3-y2)*(y3-y2);
        int b_square = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
        int c_square = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        if (a_square > b_square){
            int temp = b_square;
            b_square = a_square;
            a_square = temp;
        }
        if (b_square > c_square){
            int temp = c_square;
            c_square = b_square;
            b_square = temp;
        } // c是最長邊
        if((a_square == b_square) || (a_square == c_square) || (b_square == c_square)){
            printf("isosceles\n");
        }
        else{
        // printf("%d %d %d",a_square,b_square,c_square);
            if(a_square + b_square - c_square  == 0){
                printf("right\n"); 
            }
            else if(a_square + b_square - c_square  < 0){
                printf("obtuse\n"); 
            }
            else{
                printf("acute\n"); //acute是銳角
            }
        }
            
        }
    return 0;
    }
    

