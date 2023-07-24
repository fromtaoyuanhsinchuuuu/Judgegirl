#include <stdio.h>

int main()
{
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    int OA_CROSS_OB = x1*y2 - y1*x2;
    int OB_CROSS_OC = x2*y3 - y2*x3;
    int OC_CROSS_OD = x3*y4 - y3*x4;
    int OD_CROSS_OA = x4*y1 - y4*x1;
    if ((OA_CROSS_OB*OB_CROSS_OC) > 0 && (OB_CROSS_OC*OC_CROSS_OD) > 0 && (OC_CROSS_OD*OD_CROSS_OA) > 0 && (OD_CROSS_OA*OA_CROSS_OB) > 0){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}
