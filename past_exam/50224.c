#include <stdio.h>

int main() // 1.各位數總和最大 2.位數最少 3.數字本身最大
{
    int max_digits_sum = 0;
    int min_digits_number = 0;
    int ans_n = 0;
    int n = 0;
    int digits_sum = 0;
    int digits_number = 0;
    while (scanf("%d",&n) != EOF)
    {
        int k = n;
        digits_sum = 0;
        digits_number = 0;
        while ((k*10) / 10 != 0)
        {
            digits_sum += (k%10);
            k /= 10;
            digits_number++;
        }
        if (digits_sum > max_digits_sum || digits_sum == max_digits_sum && digits_number < min_digits_number || digits_sum == max_digits_sum && digits_number == min_digits_number && n > ans_n){
            ans_n = n;
            max_digits_sum = digits_sum;
            min_digits_number = digits_number;
        }
    }
    printf("%d",ans_n);
    return 0;
}
