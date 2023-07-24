#include "medicine.h"

void bubble_sort(Weight_and_Name arr[],int num) /* 須考慮重量與字典順序 */
{
    for (int i = 0; i < num; i++){
        for (int j = 0; j < num - 1; j++){
            if (arr[j].Weight < arr[j+1].Weight || arr[j].Weight == arr[j+1].Weight && strcmp(arr[j].Name,arr[j+1].Name) > 0){
                Weight_and_Name temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            if (!strcmp(arr[j].Name,arr[j+1].Name)){
                assert(0);
            }

        }
    }
    return;

}

void init(Medicine *medicine)
{
    medicine->maxWeight = 0;
    medicine->active_num = 0;
    medicine->inactive_num = 0;
    medicine->totalweight = 0;
    strcpy(medicine->maxIngredient,"FUckyourmother"); // 初始化要初始化乾淨!!!，不能有含糊地帶!

}
int addActive(Medicine *medicine, char *name, int weight)
{
    /* 先找有沒有 */
    for (int i = 0; i < medicine->active_num; i++){
        if (!strcmp(name,medicine->active[i].Name)){
            medicine->active[i].Weight += weight;
            medicine->totalweight += weight;
            if (medicine->active[i].Weight > medicine->maxWeight || medicine->active[i].Weight == medicine->maxWeight && strcmp(name,medicine->maxIngredient) < 0 || medicine->active_num == 0 && medicine->inactive_num == 0 ){
                medicine->maxWeight = medicine->active[i].Weight;
                strcpy(medicine->maxIngredient,name);
            }
            return medicine->active[i].Weight;
        }
    }

    if (medicine->active_num == 2){
        return -1;
    }

    if (weight > medicine->maxWeight || (weight == medicine->maxWeight && strcmp(name,medicine->maxIngredient) < 0) || (medicine->active_num == 0 && medicine->inactive_num == 0)){
        medicine->maxWeight = weight;
        strcpy(medicine->maxIngredient,name);
    }

    medicine->totalweight += weight;
    strcpy(medicine->active[medicine->active_num].Name,name);
    medicine->active[medicine->active_num].Weight = weight;
    medicine->active_num++;

    return weight;

}
int addInactive(Medicine *medicine, char *name, int weight)
{
    for (int i = 0; i < medicine->inactive_num; i++){
        if (!strcmp(name,medicine->Inactive[i].Name)){
            medicine->totalweight += weight;
            medicine->Inactive[i].Weight += weight;
            if (medicine->Inactive[i].Weight > medicine->maxWeight || medicine->Inactive[i].Weight == medicine->maxWeight && strcmp(name,medicine->maxIngredient) < 0 || medicine->active_num == 0 && medicine->inactive_num == 0){
                medicine->maxWeight = medicine->Inactive[i].Weight;
                strcpy(medicine->maxIngredient,name);
            }
            return medicine->Inactive[i].Weight;
        }
    }

    if (medicine->inactive_num == 5){
        return -1;
    }

    if (weight > medicine->maxWeight || (weight == medicine->maxWeight && strcmp(name,medicine->maxIngredient) < 0) || (medicine->active_num == 0 && medicine->inactive_num == 0)){
        medicine->maxWeight = weight;
        strcpy(medicine->maxIngredient,name);
    }

    medicine->totalweight += weight;
    strcpy(medicine->Inactive[medicine->inactive_num].Name,name);
    medicine->Inactive[medicine->inactive_num].Weight = weight;
    medicine->inactive_num++;

    
    return weight;
}
void print(Medicine *medicine)
{
    bubble_sort(medicine->active,medicine->active_num);
    printf("----- Active Ingredient begin   -----\n");
    for (int i = 0; i < medicine->active_num; i++){
        printf("%d %s\n",medicine->active[i].Weight,medicine->active[i].Name);
    }
    printf("----- end                       -----\n");

    bubble_sort(medicine->Inactive,medicine->inactive_num);
    printf("----- Inactive Ingredient begin -----\n");
    for (int i = 0; i < medicine->inactive_num; i++){
        printf("%d %s\n",medicine->Inactive[i].Weight,medicine->Inactive[i].Name);
    }
    printf("----- end                       -----\n");

    return;

}
int totalWeight(Medicine *medicine)
{
    return medicine->totalweight;
}
char *maxIngredient(Medicine *medicine)
{
    if (medicine->active_num == 0 && medicine->inactive_num == 0){
        return NULL;
    }
    return medicine->maxIngredient;

}
 
 void test_all() {
    int n, m;
    scanf("%d %d", &n, &m);
 
    Medicine *medi = (Medicine *) malloc(sizeof(Medicine) * n);
    int cmd, mid, weight;
    char name[128];
    for (int i = 0; i < n; i++)
        init(&medi[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &cmd, &mid);
        if (cmd == 1) {         // addActive
            scanf("%s %d", name, &weight);
            int af = addActive(&medi[mid], name, weight);
            printf("af %d\n", af);
        } else if (cmd == 2) {    // addInactive
            scanf("%s %d", name, &weight);
            int bf = addInactive(&medi[mid], name, weight);
            printf("bf %d\n", bf);
        } else if (cmd == 3) {    // print
            print(&medi[mid]);
        } else if (cmd == 4) {    // totalWeight
            printf("weight = %d\n", totalWeight(&medi[mid]));
        } else if (cmd == 5) {    // maxIngredient
            char *ret = maxIngredient(&medi[mid]);
            printf("main ingredient = %s\n", ret == NULL ? "NOT FOUND" : ret);
        }
    }
} 
int main() {
    test_all();
    return 0;
} 
