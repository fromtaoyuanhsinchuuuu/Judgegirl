#include <stdio.h>

long long min(long long a,long long b,long long c)
{
    long long min_num = (a <= b)? a : b;
    min_num = (min_num <= c)? min_num : c;
    return min_num;
}

long long max(long long a,long long b,long long c)
{
    long long max_num = (a >= b)? a : b;
    max_num = (max_num >= c)? max_num : c;
    return max_num;
}

long long Area_func(long long x1,long long y1,long long x2,int y2)
{
    long long  Area = (x2 - x1) * (y2 - y1);
    return Area;
}


long long two_intersect_area(long long A_x1,long long A_y1,long long A_x2,long long A_y2,long long B_x1,long long B_y1,long long B_x2,long long B_y2)
{
    long long x1 = (A_x1 >= B_x1)? A_x1 : B_x1;
    long long y1 = (A_y1 >= B_y1)? A_y1 : B_y1;
    long long x2 = (A_x2 <= B_x2)? A_x2 : B_x2;
    long long y2 = (A_y2 <= B_y2)? A_y2 : B_y2;
    long long Area = Area_func(x1,y1,x2,y2);
    // printf("Area 2 :%d\n",Area);
    return (Area > 0)? Area : 0;
    
}


long long three_intersect_area(long long A_x1,long long A_y1,long long A_x2,long long A_y2,long long B_x1,long long B_y1,long long B_x2,long long B_y2,long long C_x1,long long C_y1,long long C_x2,long long C_y2)
{
    if (two_intersect_area(A_x1,A_y1,A_x2,A_y2,B_x1,B_y1,B_x2,B_y2) != 0 && two_intersect_area(B_x1,B_y1,B_x2,B_y2,C_x1,C_y1,C_x2,C_y2) != 0 && two_intersect_area(A_x1,A_y1,A_x2,A_y2,C_x1,C_y1,C_x2,C_y2) != 0){
        long long x1 = max(A_x1,B_x1,C_x1);
        long long y1 = max(A_y1,B_y1,C_y1);
        long long x2 = min(A_x2,B_x2,C_x2);
        long long y2 = min(A_y2,B_y2,C_y2);
        long long Area = Area_func(x1,y1,x2,y2);
        return Area;
    }
    else
        return 0;
}


int main(void)
{
    long long A_x1,A_y1,A_x2,A_y2,B_x1,B_y1,B_x2,B_y2,C_x1,C_y1,C_x2,C_y2; // 1表左下角，2表右上角
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&A_x1,&A_y1,&A_x2,&A_y2,&B_x1,&B_y1,&B_x2,&B_y2,&C_x1,&C_y1,&C_x2,&C_y2);
    long long Ans = Area_func(A_x1,A_y1,A_x2,A_y2) + Area_func(B_x1,B_y1,B_x2,B_y2) + Area_func(C_x1,C_y1,C_x2,C_y2)
    - (two_intersect_area(A_x1,A_y1,A_x2,A_y2,B_x1,B_y1,B_x2,B_y2) + two_intersect_area(B_x1,B_y1,B_x2,B_y2,C_x1,C_y1,C_x2,C_y2) + two_intersect_area(A_x1,A_y1,A_x2,A_y2,C_x1,C_y1,C_x2,C_y2))
    + three_intersect_area(A_x1,A_y1,A_x2,A_y2,B_x1,B_y1,B_x2,B_y2,C_x1,C_y1,C_x2,C_y2);
    printf("%lld\n",Ans);
    return 0;
}
