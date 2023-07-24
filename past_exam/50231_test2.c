#include <stdio.h>
#include <stdbool.h>

#define KEY 0
#define TOWER_INDEX 1
#define MAX_N 106
#define MAX_S (106*106)
#define MAX_C 10

int f(int key, int S)
{
    return (77 * key + 2222) % S;
}

bool not_in_the_hashtable(int key,int S,int hashtable[MAX_S][MAX_C][2])
{
    int S_index = f(key,S);
    for (int C_index = 0; C_index < MAX_C; C_index++){
        if (hashtable[S_index][C_index][KEY] == key){
            return 0;
        }
    }
    return 1;
}
int get_key(int key,int S,int hash_table[MAX_S][MAX_C][2])
{
    int S_index = f(key,S); /*如果有找到就return那個key的tower_index，若無則return -1*/
    for (int C_index = 0 ; C_index < MAX_C ; C_index++){
        if (hash_table[S_index][C_index][KEY] == key){
            hash_table[S_index][C_index][KEY] = 0; /*取出*/
            // printf("extract %d from hash_table\n ",key);
            printf("%d ",key);
            return hash_table[S_index][C_index][TOWER_INDEX];
        }
    }
    return -1;
}

void insert_to_hash_table(int key,int S,int tower_index,int hash_table[MAX_S][MAX_C][2])
{
    int S_index = f(key,S);
    for (int C_index = 0 ; C_index < MAX_C ; C_index++){
        if (hash_table[S_index][C_index][KEY] == 0){
            hash_table[S_index][C_index][KEY] = key;
            // if (key == 1882334){
            //     printf("dickdick : 1882334\n");
            // }
            // printf("insert %d to hash_table\n",key);
            hash_table[S_index][C_index][TOWER_INDEX] = tower_index;
            break;
        }
    }
}

int main(void)
{
    int Tower_Z_index[MAX_N][MAX_N];       /* expose的row,col對應到的z_index */
    int hash_table[MAX_S][MAX_C][2] = {{{0}}};       /* [][][0]存的是key ,[][][1]存的是key代表的tower_index */
    int N,S,C;
    scanf("%d%d%d",&N,&S,&C);
    static int tower[MAX_N][MAX_N][MAX_N];
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j <= i ; j++){
            for (int k = 0 ; k <= i ; k++){
                scanf("%d",&tower[j][k][i]);
                if (k == i || j == i){
                    Tower_Z_index[j][k] = i;
                }
            }
        }
    }
    // printf("\n");
    // for (int i = 0 ; i < N ; i++){
    //     for (int j = 0 ; j < N ; j++){
    //         printf("row:%d col:%d expose:%d\n",i,j,tower[i][j][Tower_Z_index[i][j]]);
    //     }
    // } 
    int key;
    int tower_index = 0;
    int pair = 0;
    int check_tower_index1;
    int check_tower_index2;
    int tower_index1;
    int tower_index2;
    for (int row = 0 ; row < N ; row++){
        for (int col = 0 ; col < N ; col++,tower_index++){
            key = tower[row][col][Tower_Z_index[row][col]];
            // printf("row:%d col:%d z_index:%d key:%d\n",row,col,Tower_Z_index[row][col],key);
            check_tower_index1 = get_key(key,S,hash_table);
            if (check_tower_index1 != -1){
                tower_index1 = check_tower_index1;
                tower_index2 = tower_index;
                // printf("extract %d from hash_table\n",key);
                pair++;
                // printf("key:%d\n",key);
            }
            else{
                // printf("insert %d to hash_table\n",key);
                insert_to_hash_table(key,S,tower_index,hash_table);
            }
        }
    }
    // printf("pair:%d\n",pair);
    // printf("towerindex1:%d towerindex2:%d\n",tower_index1,tower_index2);
    int N1_row;
    int N1_col;
    int N2_row;
    int N2_col;
    int key1 = 1;
    int key2 = 1;
    /* 主迴圈 */
    while (pair > 0 && !(key1 == 0 && key2 == 0)){
        pair--;
        N1_row = tower_index1 / N;
        N1_col = tower_index1 % N;
        N2_row = tower_index2 / N;
        N2_col = tower_index2 % N; 
        Tower_Z_index[N1_row][N1_col]++;
        Tower_Z_index[N2_row][N2_col]++;
        key1 = tower[N1_row][N1_col][Tower_Z_index[N1_row][N1_col]];
        key2 = tower[N2_row][N2_col][Tower_Z_index[N2_row][N2_col]];
        // printf("key1:%d key2:%d\n",key1,key2);
        /* 所有expose的都要到hash_table裡 */
        if (key1 != 0){
            check_tower_index1 = get_key(key1,S,hash_table); // 找key1是不是在hashtable裡
            if (check_tower_index1 == -1){
                insert_to_hash_table(key1,S,tower_index1,hash_table);
            }
        }
        if (key1 != 0 && check_tower_index1 != -1){
            pair++;
            insert_to_hash_table(key2,S,tower_index2,hash_table);
            tower_index2 = check_tower_index1;
            continue;
        }
        if (key2 != 0){
            check_tower_index2 = get_key(key2,S,hash_table);
            // printf("key2:%d check_tower_index:%d\n",key2,check_tower_index2);
            if (check_tower_index2 == -1){
                insert_to_hash_table(key2,S,tower_index2,hash_table);
            }
        }
        if (key2 != 0 && check_tower_index2 != -1){
            pair++;
            tower_index1 = check_tower_index2;
            continue;
        }
    }
    // printf("key1=%d key2= %d\n",key1,key2);
    // for (int i = 0; i < MAX_S; i++){
    //     for (int j = 0; j < MAX_C; j++){
    //         if (hash_table[i][j][0] == 1456432){
    //             printf("%d in the hashtable\n",hash_table[i][j][0]);
    //         }
    //     }
    // }
    return 0;
}



