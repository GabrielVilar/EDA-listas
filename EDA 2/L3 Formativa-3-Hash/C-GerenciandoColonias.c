#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003  
#define MAX_WORD_LENGTH 11

typedef struct Node {
    int id;
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hashFunction(int id, const char* word) {
    unsigned int hash = id;
    while (*word) {
        hash = (hash * 131) + *word++;  
    }
    return hash % TABLE_SIZE;
}

Node* createNode(int id, const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->id = id;
        strncpy(newNode->word, word, MAX_WORD_LENGTH - 1);
        newNode->word[MAX_WORD_LENGTH - 1] = '\0';
        newNode->next = NULL;
    }
    return newNode;
}

int checkAndInsert(int id, const char* word) {
    unsigned int index = hashFunction(id, word);
    Node* current = hashTable[index];

    while (current != NULL) {
        if (current->id == id && strcmp(current->word, word) == 0) {
            return 1; 
        }
        current = current->next;
    }

    Node* newNode = createNode(id, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    return 0;
}

int main() {
    int id;
    char word[MAX_WORD_LENGTH];

    while (scanf("%d %10s", &id, word) != EOF) {
        if (checkAndInsert(id, word)) {
            printf("%d\n", id);
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}