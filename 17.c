#include  <stdio.h>
#define Maxsize 100

int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int sum[Maxsize]={0};
    for (int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            int x;
            scanf("%d",&x);
            sum[j] += x;
        }
    }
    for (int i = 0 ; i < col ; i++){
        printf("%d\n",sum[i]/row);
    }
    return 0;
}
