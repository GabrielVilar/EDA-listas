#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int size;
} PriorityQueue;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lift(int *items, int index) {
    while (index > 1 && items[index / 2] > items[index]) {
        swap(&items[index], &items[index / 2]);
        index /= 2;
    }
}

void down(int *items, int size, int index) {
    while (index * 2 <= size) {
        int smallest = index * 2;
        if (smallest < size && items[smallest] > items[smallest + 1]) {
            smallest++;
        }
        if (items[index] <= items[smallest]) {
            break;
        }
        swap(&items[index], &items[smallest]);
        index = smallest;
    }
}

void insertion(PriorityQueue *queue, int value) {
    queue->items[++queue->size] = value;
    lift(queue->items, queue->size);
}

int rmove(PriorityQueue *queue) {
    if (queue->size == 0) {
        return -1;
    }

    int top = queue->items[1];
    queue->items[1] = queue->items[queue->size--];
    down(queue->items, queue->size, 1);

    return top;
}

int main() {
    PriorityQueue queue;
    queue.size = 0;
    queue.items = (int *)malloc(sizeof(int) * 2000000);

    int operation, parameter, temporary[100];

    while (scanf("%d %d", &operation, &parameter) != EOF) {
        if (operation == 1) {
            insertion(&queue, parameter);
        } else {
            int counter;
            for (counter = 0; counter < parameter; counter++) {
                int small = rmove(&queue);
                if (small == -1) {
                    break;
                }
                temporary[counter] = small;
            }
            for (int i = 0; i < counter; i++) {
                printf("%d ", temporary[i]);
                insertion(&queue, temporary[i]);
            }
            printf("\n");
        }
    }

    free(queue.items);
    return 0;
}