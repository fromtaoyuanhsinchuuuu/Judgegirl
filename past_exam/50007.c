#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void change_inch_into_length(int length[3], int inch)
{
    length[0] = inch / 36;
    inch -= 36 * length[0];
    length[1] = inch / 12;
    inch -= 12 * length[1];
    length[2] = inch % 12;
    inch -= length[2];
    assert(inch == 0);
    return;
}

void init(int length[3]) {
    for (int i = 0; i < 3; i++){
        length[i] = 0;
    }
    return;
}
void add(int length[3], int i) {
    int total_inch = 36 * length[0] + 12 * length[1] + length[2] + i;
    change_inch_into_length(length,total_inch);
    return;
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    int total_inch = (lengtha[0] + lengthb[0]) * 36 + (lengtha[1] + lengthb[1]) * 12 + (lengtha[2] + lengthb[2]);
    change_inch_into_length(lengthc,total_inch);
    return;
    /* add your code */
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    int total_inch = (lengtha[0] - lengthb[0]) * 36 + (lengtha[1] - lengthb[1]) * 12 + (lengtha[2] - lengthb[2]);
    change_inch_into_length(lengthc,total_inch);
    return;
    /* add your code */
}

#include <stdio.h>
#include <assert.h>
// #include "length.h"
 
int main() {
    int a[3] = {-1, -1, -1}, b[3] = {-1, -1, -1};
    int c[3] = {-1, -1, -1}, d[3] = {-1, -1, -1};
    int e[3] = {-1, -1, -1}, f[3] = {-1, -1, -1};
    int cmd, x, y, z;
    scanf("%d", &cmd);
    if (cmd == 1) {
        init(a);
        printf("%d %d %d\n", a[0], a[1], a[2]);
    } else if (cmd == 2) {
        init(a);
        scanf("%d", &x);
        add(a, x);
        printf("%d %d %d\n", a[0], a[1], a[2]);
    } else if (cmd == 3) {
        init(a), init(b);
        scanf("%d %d", &x, &y);
        add(a, x), add(b, y);
        sum(a, b, c);
        printf("%d %d %d\n", c[0], c[1], c[2]);
    } else if (cmd == 4) {
        init(a), init(b), init(c), init(d);
        scanf("%d %d %d", &x, &y, &z);
        assert(x+y >= z);
        add(a, x), add(b, y);
        sum(a, b, c);
        add(d, z);
        diff(c, d, e);
        printf("%d %d %d\n", e[0], e[1], e[2]);
    }
    return 0;
}
