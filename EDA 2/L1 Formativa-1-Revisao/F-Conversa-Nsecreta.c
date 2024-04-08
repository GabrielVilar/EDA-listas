#include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute difference between two numbers
int abs_diff(int a, int b) {
    return abs(a - b);
}

// Function to check if a given position is within the capture range of the microphone
int within_capture_range(int mic_x, int mic_y, int x, int y) {
    return abs_diff(mic_x, x) <= 1 && abs_diff(mic_y, y) <= 1;
}

int main() {
    int N, M; // Size of the grid
    int mic_x, mic_y; // Microphone position
    int squares_walked; // Number of squares walked through
    int *directions; // Array to store directions

    // Read input
    scanf("%d %d", &N, &M);
    scanf("%d %d", &mic_x, &mic_y);
    scanf("%d", &squares_walked);

    // Allocate memory for directions array
    directions = (int *)malloc(squares_walked * sizeof(int));

    // Read directions
    for (int i = 0; i < squares_walked; i++) {
        scanf("%d", &directions[i]);
    }

    // Initialize count of captured minutes
    int captured_minutes = 0;

    // Initialize the position of the men
    int man1_x = 0, man1_y = 0;

    // Iterate through each square walked

    for (int i = 0; i < squares_walked; i++) {

        // Update positions based on direction
        switch (directions[i]) {
            case 1: // North
                man1_y++;                
                break;
            case 2: // South
                man1_y--;                
                break;
            case 3: // East
                man1_x++;                
                break;
            case 4: // West
                man1_x--;               
                break;
            default:
                printf("Invalid direction\n");
                break;
        }

        // Check if either man is within the capture range of the microphone
        if (within_capture_range(mic_x, mic_y, man1_x, man1_y)) {
            captured_minutes++;        
        }
    }

    // Output the result
    printf("%d\n", captured_minutes);
    
    // Free dynamically allocated memory
    free(directions);

    return 0;
}