#include <stdio.h>

#define MAX_ROWS 20
#define MAX_SEATS 25

int main() {
    int rows, seats;
    char theater[MAX_ROWS][MAX_SEATS]; // Represents the theater map
    
    // Read the number of rows and seats per row
    scanf("%d %d", &rows, &seats);
    
    // Initialize theater map with empty seats
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < seats; j++) {
            theater[i][j] = '-';
        }
    }
    
    // Read the occupied seats and mark them in the theater map
    char row;
    int seat;
    while (scanf(" %c%d", &row, &seat) != EOF) {
        theater['A' - row + rows - 1][seat - 1] = 'X'; // Mark the occupied seat
    }
    
    // Print theater map
    printf("  ");
    for (int i = 1; i <= seats; i++) {
        printf("%02d ", i);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%c ", 'A' + rows - 1 - i);
        for (int j = 0; j < seats; j++) {
            if (theater[i][j] == 'X') {
                printf("XX ");
            } else {
                printf("-- ");
            }
        }
        printf("\n");
    }
    
    return 0;
}