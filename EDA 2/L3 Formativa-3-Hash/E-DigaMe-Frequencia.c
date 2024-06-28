#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_INPUT_LENGTH 1001

typedef struct {
    char character;
    int frequency;
} CharFrequency;

int compare(const void* a, const void* b) {
    CharFrequency* cf1 = (CharFrequency*)a;
    CharFrequency* cf2 = (CharFrequency*)b;
    if (cf1->frequency != cf2->frequency) {
        return cf1->frequency - cf2->frequency;
    } else {
        return cf1->character - cf2->character;
    }
}

void processInput(char* input) {
    int frequency[MAX_CHAR] = {0};

    for (int i = 0; i < strlen(input); i++) {
        unsigned char ch = input[i];
        frequency[ch]++;
    }

    CharFrequency charFrequency[MAX_CHAR];
    int count = 0;

    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequency[i] > 0) {
            charFrequency[count].character = i;
            charFrequency[count].frequency = frequency[i];
            count++;
        }
    }

    qsort(charFrequency, count, sizeof(CharFrequency), compare);

    for (int i = 0; i < count; i++) {
        printf("%d %d\n", charFrequency[i].character, charFrequency[i].frequency);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (fgets(input, sizeof(input), stdin) != NULL) {
       
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        processInput(input);
        printf("\n"); 
    }

    return 0;
}