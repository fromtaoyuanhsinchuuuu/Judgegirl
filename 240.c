#include <stdio.h>

int main()  //不三點共線的凸四邊形
{
    int n;
    scanf("%d",&n);
    for (int i = 0 ; i < n ;i++){
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    //A(x1,y1),B(x2,y2),C(x3,y3),D(x4,y4) A,B,C,D不一定逆時針或順時針
    if (((x2-x1)*(y3-y2)-(y2-y1)*(x3-x2))*((x3-x2)*(y4-y3)-(y3-y2)*(x4-x3)) < 0){
        long long temp = x4;
        x4 = x3;
        x3 = temp;
        temp = y4;
        y4 = y3;
        y3 = temp;
    }
    if (((x4-x3)*(y1-y4)-(y4-y3)*(x1-x4))*((x3-x2)*(y4-y3)-(y3-y2)*(x4-x3))< 0){
        long long temp = x2;
        x2 = x3;
        x3 = temp;
        temp = y2;
        y2 = y3;
        y3 = temp;
    }
    if((x2-x1) == (x3-x4) && (y2-y1) == (y3-y4)){
        if (((x2-x1)*(x3-x2)+(y2-y1)*(y3-y2)) == 0 ){
            if (((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) == ((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))){
                printf("square\n");
                }
            else{
                printf("rectangle\n");
            }
        }
        else{
            if((x4-x2)*(x3-x1)+(y4-y2)*(y3-y1) == 0)
                printf("diamond\n");
            else
                printf("other\n");
        }
    }
    else{
        printf("other\n");
    }
    } 
    return 0;
}
