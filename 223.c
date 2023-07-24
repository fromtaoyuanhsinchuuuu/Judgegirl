#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

void sol(int type, int x, int y, int size)
{
    if (size == 1) return;
    if (size == 2) printf("%d %d %d\n", type, x, y);

    sol(type, x, y, size / 2);

    int dis = size / 4;
    if (type != 1) sol(3, x + dis, y + dis, size / 2);
    if (type != 2) sol(4, x - dis, y + dis, size / 2);
    if (type != 3) sol(1, x - dis, y - dis, size / 2);
    if (type != 4) sol(2, x + dis, y - dis, size / 2);
    return;
}

int main(void)
{
    int l,m;
    scanf("%d%d",&l,&m);

    int x =  l / 2, y = l / 2;
    while (l > m){
        sol(1, x, y, l);
        l /= 2;
        x += l / 2, y += l / 2;
    }
    return 0;
}