#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(Heap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[smallest], &heap->data[index]);
        minHeapify(heap, smallest);
    }
}

void maxHeapify(Heap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->data[largest], &heap->data[index]);
        maxHeapify(heap, largest);
    }
}

void insertMinHeap(Heap* heap, int value) {
    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = value;

    while (i != 0 && heap->data[(i - 1) / 2] > heap->data[i]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertMaxHeap(Heap* heap, int value) {
    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = value;

    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(Heap* heap) {
    if (heap->size <= 0) {
        return INT_MAX;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

int extractMax(Heap* heap) {
    if (heap->size <= 0) {
        return INT_MIN;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return root;
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    Heap* Ta = createHeap(N);
    Heap* Tb = createHeap(N);

    int *combined = (int *)malloc(N * sizeof(int));
    int combinedCount = 0;

    for (int i = 0; i < N; i++) {
        insertMinHeap(Ta, A[i]);
    }

    while (Ta->size > 0) {
        int TaMin = extractMin(Ta);

        if (Tb->size == 0) {
            insertMaxHeap(Tb, TaMin);
        } else {
            int TbMax = extractMax(Tb);

            if (abs(TaMin - TbMax) <= X && abs(TaMin - TbMax) > 0) {
                combined[combinedCount++] = TaMin + TbMax;
            } else {
                insertMaxHeap(Tb, TbMax);
                insertMaxHeap(Tb, TaMin);
            }
        }
    }

    printf("%d\n", combinedCount);
    for (int i = 0; i < combinedCount; i++) {
        printf("%d ", combined[i]);
    }
    printf("\n");

    free(A);
    free(Ta->data);
    free(Ta);
    free(Tb->data);
    free(Tb);
    free(combined);

    return 0;
}