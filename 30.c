#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 12

int goMaxtrix(int r,int c,int Maxtirx[MAXSIZE][MAXSIZE],int nowrow,int nowcol)
{
    if (!Maxtirx[nowrow][nowcol] || nowrow < 0 || nowcol > c - 1){
        return 0;
    }
    if (nowcol == c - 1 && nowrow == 0){
        return 1;
    }
    return (goMaxtrix(r,c,Maxtirx,nowrow - 1,nowcol) + goMaxtrix(r,c,Maxtirx,nowrow,nowcol+1));

}

int main(void)
{
    int r,c;
    scanf("%d%d",&r,&c);

    int Maxtrix[MAXSIZE][MAXSIZE];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d",&Maxtrix[i][j]);
        }
    }

    int NowRow = r - 1;
    int NowCol = 0;

    printf("%d",goMaxtrix(r,c,Maxtrix,NowRow,NowCol));

    
    
    return 0;
}
