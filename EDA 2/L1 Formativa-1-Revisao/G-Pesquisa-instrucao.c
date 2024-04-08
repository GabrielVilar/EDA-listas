#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYWORD_LENGTH 16

// Define a structure to represent each instruction
typedef struct {
    int code;
    char keyword[MAX_KEYWORD_LENGTH];
} Instruction;

// Function to compare two instructions by their code (for sorting)
int compare(const void *a, const void *b) {
    return ((Instruction*)a)->code - ((Instruction*)b)->code;
}

// Function to search for a keyword using binary search
char* binarySearch(Instruction* instructions, int n, int code) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (instructions[mid].code == code) {
            return instructions[mid].keyword;
        } else if (instructions[mid].code < code) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return "undefined";
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Allocate memory for instructions
    Instruction* instructions = (Instruction*)malloc(n * sizeof(Instruction));
    
    // Read instructions into the array
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &instructions[i].code, instructions[i].keyword);
    }
    
    // Sort the array of instructions by code
    qsort(instructions, n, sizeof(Instruction), compare);
    
    int query;
    while (scanf("%d", &query) != EOF) {
        char* keyword = binarySearch(instructions, n, query);
        printf("%s\n", keyword);
    }
    
    // Free allocated memory
    free(instructions);
    
    return 0;
}