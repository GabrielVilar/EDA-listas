#include <stdio.h>
// Function to check if the given position is within the grid
int withinGrid(int x, int y, int N, int M) {
    return (x >= 1 && x <= N && y >= 1 && y <= M);
}

int main() {
    int N, M; // Number of columns and rows
    int P;    // Number of moves
    int pa_x = 1, pa_y = 1; // Initial position of PA
    int pb_x, pb_y;         // Initial position of PB
    // Input grid dimensions
    scanf("%d %d", &N, &M);
    // Set initial position of PB
    pb_x = N;
    pb_y = M;
    // Input number of moves
    scanf("%d", &P);
    // Perform moves
    int i;
    for (i = 0; i < P; i++) {
        int move_pa, move_pb; // Direction of moves for PA and PB
        scanf("%d %d", &move_pa, &move_pb);

        // Update positions based on moves
        switch (move_pa) {
            case 1: pa_y++; break; // North
            case 2: pa_y--; break; // South
            case 3: pa_x++; break; // East
            case 4: pa_x--; break; // West
        }

        switch (move_pb) {
            case 1: pb_y++; break; // North
            case 2: pb_y--; break; // South
            case 3: pb_x++; break; // East
            case 4: pb_x--; break; // West
        }

        // Check meeting condition
        if (pa_x == pb_x && pa_y == pb_y) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa_x, pa_y, i + 1);
            return 0;
        }

        // Check leaving conditions (PA)
        if (!withinGrid(pa_x, pa_y, N, M)) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_x, pa_y, i + 1);
            return 0;
        }
        // Check leaving conditions (PB)
        if (!withinGrid(pb_x, pb_y, N, M)) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_x, pb_y, i + 1);
            return 0;
        }
    }

    printf("Nao se encontraram\n");
    return 0;
}