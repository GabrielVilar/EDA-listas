#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;

typedef struct HashTable{
    Node** table;
    int size;
}HashTable;

Node* creatNode(int key, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hashFunc(int key, int size){
    return key % size;
}

void initHashTable(HashTable* hashTable, int size){
    hashTable->size = size;
    hashTable->table = (Node**)malloc(size* sizeof(Node*));
    for (int i = 0; i < size; i++){
        hashTable->table[i] = NULL;
    }    
}

void insert(HashTable* hashTable, int key, int value){
    int hashIndex = hashFunc(key, hashTable->size);
    Node* newNode = creatNode(key, value);
    if (hashTable->table[hashIndex] == NULL) {
        hashTable->table[hashIndex] = newNode;
    } else {
        Node* temp = hashTable->table[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printHashTable(HashTable* hashTable){
    for (int i = 0; i < hashTable->size; i++) {
        printf("%d -> ", i);
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\\\n");
    }
}

void freeHashTable(HashTable* hashTable){
    for (int i = 0; i < hashTable->size; i++) {
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(hashTable->table);
}

int main(){
    int hashTableSize, vectorSize;
    int caseTest;
    scanf("%d", &caseTest);

    for (int i = 0; i < caseTest; i++){
        scanf("%d %d", &hashTableSize, &vectorSize);

        int* vector = (int*)malloc(vectorSize * sizeof(int));
        
        for (int i = 0; i < vectorSize; i++) {
            scanf("%d", &vector[i]);
        }

        HashTable hashTable;
        initHashTable(&hashTable, hashTableSize);

        for (int i = 0; i < vectorSize; i++) {
            insert(&hashTable, vector[i], vector[i]); 
        }

        printHashTable(&hashTable);

        freeHashTable(&hashTable);
        free(vector);
        printf("\n");   
    }

    return 0;
}