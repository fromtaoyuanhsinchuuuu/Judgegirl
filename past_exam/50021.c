#include "polynomial.h"

void init(Polynomial *poly, int coefficient[], int n)
{
    poly->term_num = n;
    for (int i = 0; i < MAXTERM; i++){
        poly->coefficient[i] = 0;
    }
    for (int i = 0; i < n; i++){
        poly->coefficient[i] = coefficient[i]; // 腦殘題目領導係數可以等於0
    }
    return;
}
Polynomial add(Polynomial *poly1, Polynomial *poly2)
{
    Polynomial res;
    int i = 0;
    int max_term_num = (poly1->term_num >= poly2->term_num)? poly1->term_num: poly2->term_num;
    for (;i < max_term_num; i++){
        res.coefficient[i] = poly1->coefficient[i] + poly2->coefficient[i];
    }
    for (i = max_term_num; i >= 0; i--){
        if (res.coefficient[i - 1] != 0){
            res.term_num = i;
            break;
        }
    }
    return res;

}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2)
{
    Polynomial res;
    res.term_num = poly1->term_num + poly2->term_num - 1;
    for (int i = 0; i < res.term_num; i++){
        res.coefficient[i] = 0;
    }
    for (int i = 0; i < poly1->term_num; i++){
        for (int j = 0; j < poly2->term_num; j++){
            res.coefficient[i + j] += (poly1->coefficient[i] * poly2->coefficient[j]);
        }
    }
    if (res.coefficient[res.term_num - 1] == 0){
        print(&res);
        exit(1);
    }

    return res;

}
void print(Polynomial *poly)
{
    for (int i = poly->term_num - 1; i >= 0; i--){
        if (poly->coefficient[i] == 0){
            assert(i != poly->term_num);
            continue;
        }
        else if (!(i == 1 || i == 0)){
            if (poly->coefficient[i] > 0){
                printf("+");
            }
            printf("%dx^%d",poly->coefficient[i],i);
        }
        else if (i == 0 || i == 1){
            if (poly->coefficient[i] > 0){
                printf("+");
            }
            if (i == 1){
                printf("%dx",poly->coefficient[i]);
            }
            else if (i == 0){
                printf("%d",poly->coefficient[i]);
            }
        }
    }
    printf("\n");
    return;

}

void test_specall() {
    int n, m;
    int cmds, cmd, pid, pid2;
    int v[4096];
    scanf("%d", &n);
    Polynomial *p = (Polynomial*) malloc(sizeof(Polynomial)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
            scanf("%d", &v[j]);
        init(&p[i], v, m);
    }
    scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &pid);
        if (cmd == 1) {
            print(&p[pid]);
        } else if (cmd == 2) {
            scanf("%d", &pid2);
            Polynomial ret = add(&p[pid], &p[pid2]);
            print(&ret);
        } else if (cmd == 3) {
            scanf("%d", &pid2);
            Polynomial ret = multiply(&p[pid], &p[pid2]);
            print(&ret);
        } else {
            assert(0);
        }
    }
}
int main() {
    test_specall();
    return 0;
}