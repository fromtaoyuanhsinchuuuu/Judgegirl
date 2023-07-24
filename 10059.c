#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    float re;
    float im;
} complex;
 
void init(complex *c, float a, float b)
{
    c->re = a;
    c->im = b;
}

void complex_print(complex *x)
{
    float a = x->re;
    float b = x->im;
    printf("%.3f%+.3fi\n", a, b);
}
complex complex_add(complex *x, complex *y)
{
    complex c;
    c.re = x->re + y->re;
    c.im = x->im + y->im;
    return c;

}
complex complex_sub(complex *x, complex *y)
{
    complex c;
    c.re = x->re - y->re;
    c.im = x->im - y->im;
    return c;
    
}
complex complex_mul(complex *x, complex *y)
{
    complex c;
    c.re = x->re * y->re - y->im * x->im;
    c.im = x->im * y->re + x->re * y->im;
    return c;

}

int main() {
    complex (*FUNC[])(complex *, complex *) = {
        complex_add, complex_sub, complex_mul
    };
    int cmd;
    float x, y, p, q;
    while (scanf("%d %f %f %f %f", &cmd, &x, &y, &p, &q) == 5) {
        complex *A = (complex *) malloc(sizeof(complex));
        complex *B = (complex *) malloc(sizeof(complex));
        init(A, x, y), init(B, p, q);
        complex C = FUNC[cmd](A, B);
        complex_print(&C);
    }
    return 0;
}
