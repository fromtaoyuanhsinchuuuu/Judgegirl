#include <stdio.h>
#include <stdbool.h>

#define KEY 0
#define TOWER_INDEX 1
#define MAX_N 106
#define MAX_S (106*106)
#define MAX_C 10

int f(int key, int S)
{
    return (77 * key + 2022) % S;
}

int get_key(int key,int S,int hash_table[MAX_S][MAX_C][2])
{
    int S_index = f(key,S); /*如果有找到就return那個key的tower_index，若無則return -1*/
    for (int C_index = 0 ; C_index < MAX_C ; C_index++){
        if (hash_table[S_index][C_index][KEY] == key){
            hash_table[S_index][C_index][KEY] = 0; /*取出*/
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
    printf("\n");
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j <= i ; j++){
            for (int k = 0 ; k <= i ; k++){
                if (tower[j][k][i] == 1456432)
                    printf("1456432 is in row:%d col:%d z:%d\n",j,k,i);
               
            }
        }
    }
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
            printf("row:%d col:%d z_index:%d key:%d\n",row,col,Tower_Z_index[row][col],key);
            check_tower_index1 = get_key(key,S,hash_table);
            if (check_tower_index1 != -1){
                tower_index1 = check_tower_index1;
                tower_index2 = tower_index;
                printf("extract %d from hash_table\n",key);
                pair++;
                // printf("key:%d\n",key);
            }
            else{
                if (key == 1966710)
                    printf("insert %d to hash_table\n",key);
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
    
    while (pair > 0 ){ 
        pair--;
        N1_row = tower_index1 / N;
        N1_col = tower_index1 % N;
        // printf("N1_row:%d N1_col:%d Z1:%d\n",N1_row,N1_col,Tower_Z_index[N1_row][N1_col]);
        N2_row = tower_index2 / N;
        N2_col = tower_index2 % N;
        // printf("N2_row:%d N2_col:%d Z2:%d\n",N2_row,N2_col,Tower_Z_index[N2_row][N2_col]);
        key1 = (Tower_Z_index[N1_row][N1_col] < N)? tower[N1_row][N1_col][Tower_Z_index[N1_row][N1_col]] : 0;
        // printf("tower[1][1][2]:%d\n",tower[1][1][2]);
        key2 = (Tower_Z_index[N2_row][N2_col] < N)? tower[N2_row][N2_col][Tower_Z_index[N2_row][N2_col]] : 0;
        // printf("key1:%d key2:%d\n",key1,key2);
        if (key1 == key2){
            pair++;
            printf("%d ",key1);
            printf("dick\n");
            break;
        }
        /* 找跟key1一樣的 */
        check_tower_index1 = (key1 != 0)? get_key(key1,S,hash_table) : -1;
        check_tower_index2 = (key2 != 0)? get_key(key2,S,hash_table) : -1;
        if (check_tower_index1 != -1){
            pair++;
            tower_index2 = check_tower_index1;
            insert_to_hash_table(key2,S,tower_index2,hash_table);
            Tower_Z_index[N1_row][N1_col]++;
            continue;
        }
        if (check_tower_index2 != -1){
            Tower_Z_index[N2_row][N2_col]++;
            pair++;
            tower_index1 = check_tower_index2;
            insert_to_hash_table(key1,S,tower_index1,hash_table);
            continue;
        }
    }
    printf("\n");
    for (int i = 0 ; i < MAX_S ; i++){
        for (int j = 0 ; j < MAX_C ; j++){
            if (hash_table[i][j][0] == 1480371){
                printf("%d in the hash_table\n tower_index:%d",hash_table[i][j][0],hash_table[i][j][1]);
            }
        }
    }


    return 0;
}



