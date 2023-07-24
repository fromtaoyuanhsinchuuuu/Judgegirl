#include <stdio.h>

void bubble_sort(int array[4])
{
    for (int i = 0 ; i < 4 ; i++){
        for (int j = i ; j < 4 ; j++){ // 由大到小排
            if (array[i] < array[j]){
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int max(int a,int b,int c,int d)
{
    int max = (a >= b)? a : b;
    max = (max >= c)? max : c;
    max = (max >= d)? max : d;
    return max;
}

int min(int a,int b,int c,int d)
{
    int min = (a <= b)? a : b;
    min = (min <= c)? min : c;
    min = (min <= d)? min : d;
    return min;
} 

int main(void)
{
    int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
    scanf("%d%d%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy);
    if (Cx < Ax){
        int temp = Cx;
        Cx = Ax;
        Ax = temp;
        temp = Cy;
        Cy = Ay;
        Ay = temp;
    }
    int sort_line_x[4] = {Ax,Bx,Cx,Dx};
    int sort_line_y[4] = {Ay,By,Cy,Dy};
    int perimeter = 2*(max(Ax,Bx,Cx,Dx) - min(Ax,Bx,Cx,Dx))+2*(max(Ay,By,Cy,Dy) - min(Ay,By,Cy,Dy));
    bubble_sort(sort_line_x);
    bubble_sort(sort_line_y);
    int Area = (Cx-Ax)*(Cy-Ay)-(Cx-Bx)*(By-Ay)-(Cy-Dy)*(Dx-Ax);
    printf("%d\n%d",perimeter,Area);
    return 0;
}
