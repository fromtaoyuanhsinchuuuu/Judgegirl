#include "map.h"

void bubble_sort(Key_Val pairARR[],int size)
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (pairARR[j].key > pairARR[j+1].key){
                Key_Val temp = pairARR[j];
                pairARR[j] = pairARR[j+1];
                pairARR[j+1] = temp;
            }
            else if (pairARR[j].key == pairARR[j+1].key){
                assert(0);
            }
        }
    }
    return;
}
void init(Map *map)
{
    map->size = 0;
    return;
}

void print(Map *map)
{
    printf("----- map begin -----\n");
    bubble_sort(map->pairARR,map->size);
    for (int i = 0; i < map->size; i++){
        printf("%d %s\n",map->pairARR[i].key,map->pairARR[i].val);
    }
    printf("----- end       -----\n");
    return;
}

int map(Map *map, const int key, const char *value) 
{
    for (int i = 0; i < map->size; i++){
        if (map->pairARR[i].key == key){
            strcpy(map->pairARR[i].val,value);
            return 0;
        }
    }
    map->pairARR[map->size].key = key;
    strcpy(map->pairARR[map->size].val,value);
    map->size++;
    return 1;
}

int numPairs(Map *map)
{
    return map->size;

}

const char *getValue(Map *map, const int key)
{
    for (int i = 0; i < map->size; i++){
        if (key == map->pairARR[i].key){
            return map->pairARR[i].val;
        }
    }
    return NULL;

}

int unmap(Map *map, int key)
{
    int breakIndex = -1;
    for (int i = 0; i < map->size; i++){
        if (key == map->pairARR[i].key){
            breakIndex = i;
            break;
        }
    }
    if (breakIndex == -1){
        return 0;
    }
    /* 從breakIndex開始每個要補上來 */
    for (int i = breakIndex; i < map->size - 1; i++){
        map->pairARR[i].key = map->pairARR[i+1].key;
        strcpy(map->pairARR[i].val,map->pairARR[i+1].val);
    }
    map->size--;
    return 1;

}

int reverseMap(Map *map, const char *value, int keys[])
{
    int key_index = 0;
    for (int i = 0; i < map->size; i++){
        if (!strcmp(value,map->pairARR[i].val)){
            keys[key_index] = map->pairARR[i].key;
            key_index++;
        }
    }
    for (int i = 0; i < key_index; i++){
        for (int j = 0; j < key_index - 1; j++){
            if (keys[j] > keys[j + 1]){
                int temp = keys[j+1];
                keys[j+1] = keys[j];
                keys[j] = temp;
            }
            else if (keys[j] == keys[j+1]){
                assert(0);
            }
        }
    }
    return key_index;

}

void test_spec0(Map *maps, int map_n) {
	for (int i = 0; i < map_n; i++)
		init(&maps[i]);
	for (int i = 0; i < map_n; i++)
		print(&maps[i]);
}
void test_spec1(Map *maps, int map_n) {
	for (int i = 0; i < map_n; i++)
		init(&maps[i]);
	int cmds, mid, cmd, key;
	char val[128];	
	scanf("%d", &cmds);
	for (int i = 0; i < cmds; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &mid);
			print(&maps[mid]);
		} else if (cmd == 2) {	
			scanf("%d %d %s", &mid, &key, val);
			int f = map(&maps[mid], key, val);
			printf("mf %d\n", f);
		} else {
			assert(false);
		}
	}
}
void test_spec2(Map *maps, int map_n) {
	for (int i = 0; i < map_n; i++)
		init(&maps[i]);
	int cmds, mid, cmd, key;
	char val[128];	
	scanf("%d", &cmds);
	for (int i = 0; i < cmds; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &mid);
			print(&maps[mid]);
		} else if (cmd == 2) {	
			scanf("%d %d %s", &mid, &key, val);
			int f = map(&maps[mid], key, val);
			printf("mf %d\n", f);
		} else if (cmd == 3) {
			scanf("%d %d", &mid, &key);
			int f = unmap(&maps[mid], key);
			printf("uf %d\n", f);
		} else {
			assert(false);
		}
	}
}
void test_spec3(Map *maps, int map_n) {
	for (int i = 0; i < map_n; i++)
		init(&maps[i]);
	int cmds, mid, cmd, key;
	char val[128];
	int keylist[1024];
	scanf("%d", &cmds);
	for (int i = 0; i < cmds; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &mid);
			print(&maps[mid]);
		} else if (cmd == 2) {	
			scanf("%d %d %s", &mid, &key, val);
			int f = map(&maps[mid], key, val);
			printf("mf %d\n", f);
		} else if (cmd == 3) {
			scanf("%d %d", &mid, &key);
			int f = unmap(&maps[mid], key);
			printf("uf %d\n", f);
		} else if (cmd == 4) {
			scanf("%d %s", &mid, val);
			int keylist_n = reverseMap(&maps[mid], val, keylist);
			printf("list");
			for (int i = 0; i < keylist_n; i++)
				printf(" %d", keylist[i]);
			puts("");
		} else {
			assert(false);
		}
	}
}
void test_spec4(Map *maps, int map_n) {
	for (int i = 0; i < map_n; i++)
		init(&maps[i]);
	int cmds, mid, cmd, key;
	char val[128];
	int keylist[1024];
	scanf("%d", &cmds);
	for (int i = 0; i < cmds; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			assert(false);
			scanf("%d", &mid);
			print(&maps[mid]);
		} else if (cmd == 2) {	
			scanf("%d %d %s", &mid, &key, val);
			int f = map(&maps[mid], key, val);
			printf("mf %d\n", f);
		} else if (cmd == 3) {
			scanf("%d %d", &mid, &key);
			int f = unmap(&maps[mid], key);
			printf("uf %d\n", f);
		} else if (cmd == 4) {
			assert(false);
			scanf("%d %s", &mid, val);
			int keylist_n = reverseMap(&maps[mid], val, keylist);
			assert(keylist_n <= 1024);
			for (int i = 0; i < keylist_n; i++)
				printf("%d%c", keylist[i], " \n"[i == keylist_n-1]);
		} else if (cmd == 5) {
			scanf("%d", &mid);
			int ret = numPairs(&maps[mid]);
			assert(ret <= 1024);
			printf("size %d\n", ret);
		} else {
			assert(false);
		}
	}
}
void test_spec5(Map *maps, int map_n) {
	for (int i = 0; i < map_n; i++)
		init(&maps[i]);
	int cmds, mid, cmd, key;
	char val[128];
	int keylist[1024];
	scanf("%d", &cmds);
	for (int i = 0; i < cmds; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &mid);
			print(&maps[mid]);
		} else if (cmd == 2) {	
			scanf("%d %d %s", &mid, &key, val);
			int f = map(&maps[mid], key, val);
			printf("mf %d\n", f);
		} else if (cmd == 3) {
			assert(false);
		} else if (cmd == 4) {
			assert(false);
		} else if (cmd == 5) {
			assert(false);
		} else if (cmd == 6) {
			scanf("%d %d", &mid, &key);
			const char *val = getValue(&maps[mid], key);
			printf("%s\n", val == NULL ? "NOT FOUND" : val);
		}
	}
}
int main() {
	int spec;
	while (scanf("%d", &spec) == 1) {
		int map_n = 32;
		Map *maps = (Map *) malloc(sizeof(Map) * map_n);
		if (spec == 0) {
			test_spec0(maps, map_n);
		} else if (spec == 1) {
			test_spec1(maps, map_n);
		} else if (spec == 2) {
			test_spec2(maps, map_n);
		} else if (spec == 3) {
			test_spec3(maps, map_n);
		} else if (spec == 4) {
			test_spec4(maps, map_n);
		} else if (spec == 5) {
			test_spec5(maps, map_n);
		}
		free(maps);
	}
	return 0;
}