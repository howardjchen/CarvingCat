
#include <stdio.h>
#include <stdlib.h>

struct hash_map
{
    int key;
    int val;
};

/** Initialize your data structure here. */
struct hash_map* myHashMapCreate() {
    int i = 0;
    
    struct hash_map *hash_map = malloc(1000000*sizeof(hash_map));
    for(i = 0; i < 1000000; i++)
    {
        hash_map[i].val = -1;
        hash_map[i].key = -1;
    }
    
    return hash_map;
}

/** value will always be non-negative. */
void myHashMapPut(struct hash_map* obj, int key, int value) {
    
    obj[key].val = value;
    obj[key].key = key;
        
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(struct hash_map* obj, int key) {
    
    return obj[key].val;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(struct hash_map* obj, int key) {
    
        obj[key].val = -1;
}

void myHashMapFree(struct hash_map* obj) {
    
    free(obj);
}

int main()
{
    int key = 1;
    
    struct hash_map* obj = myHashMapCreate();

    myHashMapPut(obj, key, 123);

    int param_2 = myHashMapGet(obj, key);

    printf("hash val = %d\n", param_2);
 
    myHashMapRemove(obj, key);
 
    myHashMapFree(obj);

    return 0;
}