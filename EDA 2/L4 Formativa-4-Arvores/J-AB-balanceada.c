#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5000

typedef struct Node {
    int parent;
    int left;
    int right;
} Node;

Node tree[MAX_NODES];
int height[MAX_NODES];

int calculate_height(int node) {
    if (node == 0) {
        return 0; 
    }

    if (height[node] != -1) {
        return height[node];
    }

    int left_height = calculate_height(tree[node].left);
    int right_height = calculate_height(tree[node].right);

    height[node] = 1 + ((left_height > right_height) ? left_height : right_height);

    return height[node];
}

int is_balanced(int node) {
    if (node == 0) {
        return 1; 
    }

    int left_height = height[tree[node].left];
    int right_height = height[tree[node].right];

    if (abs(left_height - right_height) <= 1 &&
        is_balanced(tree[node].left) &&
        is_balanced(tree[node].right)) {
        return 1;
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        tree[i].parent = 0;
        tree[i].left = 0;
        tree[i].right = 0;
        height[i] = -1;
    }

    for (int i = 2; i <= N; ++i) {
        int parent;
        scanf("%d", &parent);

        if (tree[parent].left == 0) {
            tree[parent].left = i;
        } else {
            tree[parent].right = i;
        }
        tree[i].parent = parent;
    }

    int root = 1;
    calculate_height(root);

    if (is_balanced(root)) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }

    return 0;
}
