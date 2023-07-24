#include <stdio.h>
#define four_sum (a*a*a*a + b*b*b*b + c*c*c*c + d*d*d*d)
#define three_sum (a*a*a + b*b*b+ c*c*c + d*d*d)
#define two_sum (a*a + b*b + c*c + d*d)
#define one_sum (a + b + c + d)

int main(){
    int ans_one,ans_two,ans_three,ans_four;
    scanf("%d%d%d%d",&ans_one,&ans_two,&ans_three,&ans_four);
    int a = 4,b = 3,c = 2,d = 1;
    while ((one_sum != ans_one || two_sum != ans_two || three_sum != ans_three || four_sum != ans_four) && a <= 256){
        a++;
        for (int i = a-1 ; (one_sum != ans_one || two_sum != ans_two || three_sum != ans_three || four_sum != ans_four) && i >= 3 ; i-- ){
            b = i;
            for (int j = b-1 ; (one_sum != ans_one || two_sum != ans_two || three_sum != ans_three || four_sum != ans_four) && j >= 2 ; j-- ){
                c = j;
                for (int k = c-1 ;  (one_sum != ans_one || two_sum != ans_two || three_sum != ans_three || four_sum != ans_four) && k >= 1 ; k--){
                    d = k;
                }
            }
        }
    }
    if(a != 257){
    printf("%d\n%d\n%d\n%d",a,b,c,d);
    }
    else{
        printf("-1");
    }
    return 0;
}
