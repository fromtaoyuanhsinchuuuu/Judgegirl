#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 100
#define MAXNAME 51

#define MAX_NUM 2e9

typedef struct {
    char name[MAXNAME];
    int amount;
    int price;

} Raw_material;

typedef struct{
    char ingredient_name[MAXNAME];
    int num;
} Ingredient;

typedef struct{
    char name[MAXNAME];
    int ingredient_num;
    Ingredient ingrid[MAXM];
    int price;
} Product;

int Profit(Raw_material raw[],Product now_product,int N)
{
    int min_num = MAX_NUM;
    /* 先算最多可以做幾個 */
    for (int i = 0; i < now_product.ingredient_num; i++){
        for (int j = 0; j < N; j++){
            if (!strcmp(raw[j].name,now_product.ingrid[i].ingredient_name)){
                if (raw[j].amount / now_product.ingrid[i].num < min_num){
                    min_num = raw[j].amount / now_product.ingrid[i].num;
                }

            }
        }
    }
    int single_profit = now_product.price;
    for (int i = 0; i < now_product.ingredient_num; i++){
        for (int j = 0; j < N; j++){
            if (!strcmp(raw[j].name,now_product.ingrid[i].ingredient_name)){
                single_profit -= now_product.ingrid[i].num * raw[j].price;

            }
        }
    }

return single_profit * min_num;
    

    
}

int main(void)
{
    int N,M;
    scanf("%d%d",&N,&M);

    Raw_material raw[MAXN];
    for (int i = 0; i < N; i++){
        scanf("%s %d %d",&raw[i].name,&raw[i].amount,&raw[i].price);
    }
    Product product[MAXM];
    for (int i = 0; i < M; i++){
        scanf("%s %d",&product[i].name,&product[i].ingredient_num);
        for (int j = 0; j < product[i].ingredient_num; j++){
            scanf("%s %d",&(product[i].ingrid[j].ingredient_name),&(product[i].ingrid[j].num));
        }
        scanf("%d",&product[i].price);
    }
    int ans_profit = -1;
    char ans_product[MAXNAME];

    for (int i = 0; i < M; i++){
        int nowProfit = Profit(raw,product[i],N);
        if (nowProfit > ans_profit || nowProfit == ans_profit && strcmp(product[i].name,ans_product) < 0){
            strcpy(ans_product,product[i].name);
            ans_profit = nowProfit;
        }
    }
    printf("%s %d\n",ans_product,ans_profit);



    
    
    return 0;
}
