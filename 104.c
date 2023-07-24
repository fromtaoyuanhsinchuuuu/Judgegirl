#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define D 0
#define E 1
#define F 2

#define X 0
#define Y 1
#define Z 2

#define Dimension 3
#define MAXARR 10000

bool parallel(int nowvector[Dimension],int ans[Dimension])
{
        // printf("nowvec[%d]:%d ans[%d]:%d\n",i,nowvector[i],i,ans[i]);
    if (nowvector[X] == 0 || nowvector[Y] == 0 || nowvector[Z] == 0 || !(ans[X] / (float)nowvector[X] == ans[Y] / (float)nowvector[Y] && ans[Y] / (float)nowvector[Y] == ans[Z] / (float)nowvector[Z] && ans[Z] / nowvector[Z] == ans[Z] / (float)nowvector[Z] )){
        return 0;
    }
    return 1;

}

bool combination(int nowvector[Dimension],int DEF_vector[3][Dimension],int TargetVector[Dimension])
{
    // printf("nowVector:%d %d %d\n",nowvector[X],nowvector[Y],nowvector[Z]);
    if (TargetVector[X] - nowvector[X] < 0 || TargetVector[Y] - nowvector[Y] < 0 || TargetVector[Z] - nowvector[Z] < 0){
        return 0;
    }

    if (parallel(nowvector,TargetVector)){
        return 1;
    }


    int plus_D_vector[Dimension] = {nowvector[X] + DEF_vector[D][X],nowvector[Y] + DEF_vector[D][Y],nowvector[Z] + DEF_vector[D][Z]};
    int plus_E_vector[Dimension] = {nowvector[X] + DEF_vector[E][X],nowvector[Y] + DEF_vector[E][Y],nowvector[Z] + DEF_vector[E][Z]};
    int plus_F_vector[Dimension] = {nowvector[X] + DEF_vector[F][X],nowvector[Y] + DEF_vector[F][Y],nowvector[Z] + DEF_vector[F][Z]};

    if (combination(plus_D_vector,DEF_vector,TargetVector) || 
        combination(plus_E_vector,DEF_vector,TargetVector) ||
        combination(plus_F_vector,DEF_vector,TargetVector)){
        return 1;
    }

    return 0;
}

void readVector(int i,int n,int DEF_vector[Dimension][Dimension])
{

    if (i == n){
        return;
    }

    int TargetArr[Dimension];
    int startArr[Dimension] = {};

    scanf("%d%d%d",&TargetArr[X],&TargetArr[Y],&TargetArr[Z]);
    
    if (combination(startArr,DEF_vector,TargetArr)){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }

    readVector(i+1,n,DEF_vector);
    

}

int main(void)
{
    int DEF_vector[Dimension][Dimension];
    scanf("%d%d%d%d%d%d%d%d%d",&DEF_vector[D][X],&DEF_vector[D][Y],&DEF_vector[D][Z],&DEF_vector[E][X],&DEF_vector[E][Y],&DEF_vector[E][Z],&DEF_vector[F][X],&DEF_vector[F][Y],&DEF_vector[F][Z]);

    int n;
    scanf("%d",&n);

    int TargetVector[Dimension];
    int startArr[Dimension] = {};
    
    readVector(0,n,DEF_vector);

    
    
    return 0;
}
