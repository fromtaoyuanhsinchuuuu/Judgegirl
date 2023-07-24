#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define NOW 0
#define NEXT 1

#define MAXN 20

typedef struct {
    int numerator; // 分子
    int denominator; // 分母
} Frac;

int gcd(int a, int b)
{
    return (a % b == 0)? b: gcd(b, a % b);
}

void modifyFrac(Frac *frac)
{
    int gcd_num = gcd(frac->numerator, frac->denominator);
    frac->numerator /= gcd_num, frac->denominator /= gcd_num;
    return;
}

Frac mutiply(Frac frac1, Frac frac2)
{
    Frac ret;
    ret.numerator = frac1.numerator * frac2.numerator;
    ret.denominator = frac1.denominator * frac2.denominator;
    modifyFrac(&ret);
    return ret;
}

Frac add(Frac frac1, Frac frac2)
{
    Frac ret;
    int lcm = (frac1.denominator * frac2.denominator) / gcd(frac1.denominator, frac2.denominator);
    ret.denominator = lcm;
    ret.numerator = frac1.numerator * (lcm / frac1.denominator) + frac2.numerator * (lcm / frac2.denominator);
    modifyFrac(&ret);
    return ret;
}

void modifyANS(int left, int right, int j, Frac ans[2][MAXN])
{
    Frac leftFrac, rightFrac;
    leftFrac.denominator = left + right, leftFrac.numerator = left, rightFrac.denominator = left + right, rightFrac.numerator = right;
    modifyFrac(&leftFrac), modifyFrac(&rightFrac);

    if (j == 1) ans[NEXT][j] = mutiply(ans[NOW][j], leftFrac);
    else ans[NEXT][j] = add(ans[NEXT][j], mutiply(ans[NOW][j], leftFrac));
    ans[NEXT][j + 1] = mutiply(ans[NOW][j], rightFrac);
    return;
}

int main(void)
{
    Frac ans[2][MAXN];

    ans[NEXT][1].denominator = 1, ans[NEXT][1].numerator = 1;

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++){
        for (int it = 1; it <= i; it++){
            ans[NOW][it] = ans[NEXT][it];
        }
        int left = -1, right = -1;
        for (int j = 1; j <= i; j++){
            scanf("%d%d", &left, &right);
            modifyANS(left, right, j, ans);
        }
    }
    for (int i = 1; i <= N + 1; i++){
        printf("%d/%d\n", ans[NEXT][i].numerator, ans[NEXT][i].denominator);
    }

    
    return 0;
}
