#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int isBalanced(struct Node* node) {
    if (node == NULL) {
        return 1; 
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    int diff = abs(leftHeight - rightHeight);

    if (diff > 1) {
        return 0;
    }

    return isBalanced(node->left) && isBalanced(node->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int parents[N];
    for (int i = 1; i < N; i++) {
        scanf("%d", &parents[i]);
    }

    struct Node* nodes[N]; 
    for (int i = 0; i < N; i++) {
        nodes[i] = newNode(i + 1); 
    }

    for (int i = 1; i < N; i++) {
        int parent = parents[i] - 1;
        if (nodes[parent]->left == NULL) {
            nodes[parent]->left = nodes[i];
        } else {
            nodes[parent]->right = nodes[i];
        }
    }

    if (isBalanced(nodes[0])) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
