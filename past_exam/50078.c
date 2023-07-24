#include <stdio.h>

int main()
{
    int Ax,Ay,Bx,By,Cx,Cy;
    scanf("%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
    int Dx = Cx + (Bx - Ax);
    int Dy = Cy + (By - Ay);
    int Ex = Cx + (Ax - Bx);
    int Ey = Cy + (Ay - By);
    int Fx = Bx + (Ax - Cx);
    int Fy = By + (Ay - Cy);
    printf("%d\n%d\n%d\n%d\n%d\n%d",Dx,Dy,Ex,Ey,Fx,Fy);
    return 0;
}
