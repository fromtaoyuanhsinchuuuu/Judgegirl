# include <stdio.h>

int main(){
    long long a,b,c,d;
    while (scanf("%lld%lld%lld%lld",&a,&b,&c,&d) != EOF){
        // printf("%d",a);
        long long a_gcd = a;
        long long b_gcd = b;
        while ( a_gcd % b_gcd != 0){
            a_gcd %= b_gcd;
            long long temp = b_gcd;        // 以後看到有相乘的動作，一率開long long
            b_gcd = a_gcd;
            a_gcd = temp;
        }
        long long c_gcd = c;
        long long d_gcd = d;
        while (c_gcd % d_gcd != 0){
             c_gcd %= d_gcd;
            long long temp = d_gcd;
            d_gcd = c_gcd;
            c_gcd = temp;
        }
 
        long long a_and_b_ba = a*b/b_gcd;
        long long c_and_d_ba = c*d/d_gcd;
        long long k = a_and_b_ba;
        long long m = c_and_d_ba;
        while (a_and_b_ba % c_and_d_ba != 0){
            a_and_b_ba %= c_and_d_ba;
            long long temp = c_and_d_ba;
            c_and_d_ba = a_and_b_ba;
            a_and_b_ba = temp;
        }
        long long a_b_c_d_ba = k*m/c_and_d_ba;
        // printf("%d",a_b_c_d_ba);
        // printf("%da:",a);
        k = a_b_c_d_ba / a;
        printf("%lld\n",k);
    }
}