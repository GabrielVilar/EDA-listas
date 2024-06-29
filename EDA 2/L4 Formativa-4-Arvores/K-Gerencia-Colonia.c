#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1048576

#define MAX_FOOD_NAME 11

typedef struct HashEntry {
    int colony;
    char food[MAX_FOOD_NAME];
    struct HashEntry* next;
} HashEntry;

HashEntry* hashTable[TABLE_SIZE];
unsigned int hash(int colony, const char* food) {
    unsigned int hashValue = colony;
    while (*food) {
        hashValue = (hashValue * 31 + *food) % TABLE_SIZE;
        food++;
    }
    return hashValue;
}

int insert(int colony, const char* food) {
    unsigned int hashValue = hash(colony, food);
    HashEntry* entry = hashTable[hashValue];
    while (entry != NULL) {
        if (entry->colony == colony && strcmp(entry->food, food) == 0) {
            return colony; 
        }
        entry = entry->next;
    }

    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->colony = colony;
    strcpy(newEntry->food, food);
    newEntry->next = hashTable[hashValue];
    hashTable[hashValue] = newEntry;
    return -1; 
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashEntry* entry = hashTable[i];
        while (entry != NULL) {
            HashEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

int main() {
    int colony;
    char food[MAX_FOOD_NAME];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    while (scanf("%d %s", &colony, food) != EOF) {
        int result = insert(colony, food);
        if (result != -1) {
            printf("%d\n", result);
        }
    }

    freeHashTable();

    return 0;
}
