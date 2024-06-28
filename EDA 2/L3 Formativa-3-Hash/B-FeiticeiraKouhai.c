#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long int id;
    long int item;
    struct Node* next;
} Node;

typedef struct HashTable {
    long int size;
    long int totalItems;
    Node** table;
} HashTable;

Node* createNode(long int id, long int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

unsigned int hashFunction(long int id, long int size) {
    return abs(id) % size;
}

HashTable* createHashTable(long int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->totalItems = 0;
    hashTable->table = (Node**)malloc(size * sizeof(Node*));
    for (long int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insertItem(HashTable* hashTable, long int id, long int item) {
    unsigned int hashIndex = hashFunction(id, hashTable->size);
    Node* temp = hashTable->table[hashIndex];

    while (temp != NULL) {
        if (temp->id == id) {
            if (item < 0) {
                long int newQuantity = temp->item + item;
                if (newQuantity < 0) {
                    hashTable->totalItems -= temp->item;
                    temp->item = 0;
                } else {
                    hashTable->totalItems += item;
                    temp->item = newQuantity;
                }
            } else {
                temp->item += item;
                hashTable->totalItems += item;
            }
            return;
        }
        temp = temp->next;
    }

    if (item < 0) {
        return;
    }

    Node* newNode = createNode(id, item);
    newNode->next = hashTable->table[hashIndex];
    hashTable->table[hashIndex] = newNode;
    hashTable->totalItems += item;
}

void freeHashTable(HashTable* hashTable) {
    for (long int i = 0; i < hashTable->size; i++) {
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

int main() {
    int N;
    scanf("%d", &N);

    HashTable* hashTable = createHashTable(N);

    for (int i = 0; i < N; i++) {
        long int id, item;
        scanf("%ld %ld", &id, &item);
        insertItem(hashTable, id, item);
    }

    printf("%ld\n", hashTable->totalItems);

    freeHashTable(hashTable);
    return 0;
}