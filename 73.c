#include <stdio.h>

int main()
{
    int n;
    int remain_0=0,remain_1=0,remain_2=0;
    scanf("%d",&n);
    for (int i = 0;i < n;i++){
        int div;
        scanf("%d",&div);
        int remain = div%3;
        switch (remain)
        {
        case 0/* constant-expression */:
            remain_0 += 1;/* code */
            break;
        case 1:
            remain_1 += 1;
            break;
        case 2:
            remain_2 += 1;
            break;
        default:
            break;
        }

    }
    printf("%d %d %d",remain_0,remain_1,remain_2);
    return 0;
}
