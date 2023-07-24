#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef unsigned long long Set;

void init(Set *set)
{
    *set = 0;
    return;
}

void add(Set *set, int i)
{
    Set k = 1;
    for (int j = 0; j < i; j++){
        k <<= 1;
    }
    *set += k;
    return;
}

void has(Set set, int i)
{
    Set k = 1;
    for (int j = 0; j < i; j++){
        k <<= 1;
    }
    // printf("k:%lld\n",k);
    // printf("k & set == %lld",k & set);
    if ((k & set) == 0){
        printf("set does not have %d\n",i);
    }
    else{
        printf("set has %d\n",i);
    }
    return;
}

Set setUnion(Set a, Set b)
{
    return (a | b);
}
Set setIntersect(Set a, Set b)
{
    return (a & b);
}
Set setDifference(Set a, Set b)
{
    return (a ^ b);
}

