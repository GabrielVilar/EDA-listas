#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003  
#define MAX_WORD_LENGTH 17

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    int votes;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hashFunction(const char* word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash * 131) + *word++;  
    }
    return hash % TABLE_SIZE;
}

Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strncpy(newNode->word, word, MAX_WORD_LENGTH - 1);
        newNode->word[MAX_WORD_LENGTH - 1] = '\0';
        newNode->votes = 0;
        newNode->next = NULL;
    }
    return newNode;
}

Node* findNode(const char* word) {
    unsigned int index = hashFunction(word);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertOrUpdateNode(const char* word, int operation) {
    unsigned int index = hashFunction(word);
    Node* current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            if (operation == 1) {
                current->votes += 1; 
            } else if (operation == 3) {
                current->votes = 0;  
            }
            return;
        }
        current = current->next;
    }

    if (operation == 1) {
        Node* newNode = createNode(word);
        newNode->votes = 1; 
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void printVotes(const char* word) {
    Node* node = findNode(word);
    if (node != NULL) {
        printf("%d\n", node->votes);
    } else {
        printf("0\n");
    }
}

int main() {
    int id;
    char word[MAX_WORD_LENGTH];

    while (scanf("%d %16s", &id, word) != EOF) {
        switch (id) {
            case 1:
                insertOrUpdateNode(word, 1);
                break;
            case 2:
                printVotes(word);
                break;
            case 3:
                insertOrUpdateNode(word, 3);
                break;
            default:
                
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