#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a % b == 0){
        return b;
    }
    return gcd(b,a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b / gcd(a,b));
}

typedef struct {
    long long a, b;
} Frac;

Frac normal(long long a, long long b) {
    Frac c;
    c.a = (a / gcd(a,b));
    c.b = (b / gcd(a,b));
    return c;

    /* add your code */
}
Frac add(Frac x, Frac y) {
    ll lcm_x_y = lcm(x.b,y.b);
    ll a = x.a * (lcm_x_y / x.b) + y.a * (lcm_x_y / y.b);
    Frac c;
    c.a = a;
    c.b = lcm_x_y;
    return c;
}
Frac subtract(Frac x, Frac y) {
    ll lcm_x_y = lcm(x.b,y.b);
    ll a = x.a * (lcm_x_y / x.b) - y.a * (lcm_x_y / y.b);
    Frac c;
    c.a = a;
    c.b = lcm_x_y;
    return c;
    /* add your code */
}
Frac multipy(Frac x, Frac y) {
    int a,b;
    a = x.a * y.a;
    b = x.b * y.b;
    ll gcd_a_b = gcd(a,b);
    Frac c;
    c.a = a / gcd(a,b);
    c.b = b / gcd(a,b);
    return c;
    /* add your code */
}
Frac divide(Frac x, Frac y) {
    ll temp = y.a;
    y.a = y.b;
    y.b = temp;
    return multipy(x,y);
    /* add your code */
}



int main() {
    int cmd, x, y, z, w;
    Frac a, b, c;
    scanf("%d", &cmd);
    scanf("%d %d %d %d", &x, &y, &z, &w);
    a = normal(x, y), b = normal(z, w);
    if (cmd == 1) {
        c = add(a, b);
    } else if (cmd == 2) {
        c = subtract(a, b);
    } else if (cmd == 3) {
        c = multipy(a, b);
    } else if (cmd == 4) {
        c = divide(a, b);
    }
    printf("%lld / %lld\n", c.a, c.b);
    return 0;
}
