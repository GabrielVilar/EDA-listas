#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *left, *right;
} node;

node* create_node(char data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int find_index(char* str, char value, int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (str[i] == value) {
            return i;
        }
    }
    return -1;
}

node* build_tree(char* prefix, char* infix, int in_start, int in_end, int* pre_index) {
    if (in_start > in_end) {
        return NULL;
    }
    
    char current = prefix[*pre_index];
    (*pre_index)++;
    node *new_node = create_node(current);

    if (in_start == in_end) {
        return new_node;
    }

    int in_index = find_index(infix, current, in_start, in_end);

    new_node->left = build_tree(prefix, infix, in_start, in_index - 1, pre_index);
    new_node->right = build_tree(prefix, infix, in_index + 1, in_end, pre_index);

    return new_node;
}

void post_order(node *root) {
    if (root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%c", root->data);
}

int main() {
    int C;
    scanf("%d", &C);
    
    while (C--) {
        int N;
        char prefix[55], infix[55];
        
        scanf("%d %s %s", &N, prefix, infix);
        
        int pre_index = 0;
        node *root = build_tree(prefix, infix, 0, N - 1, &pre_index);
        
        post_order(root);
        printf("\n");
    }
    
    return 0;
}