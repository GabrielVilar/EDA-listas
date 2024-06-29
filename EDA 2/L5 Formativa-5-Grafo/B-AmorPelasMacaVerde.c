#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int type;  
    int left;  
    int right; 
} Node;

void bfs(Node nodes[], int n) {
    int level_counts[n][2]; 
    for (int i = 0; i < n; i++) {
        level_counts[i][0] = 0; 
        level_counts[i][1] = 0; 
    }

    int queue[n];
    int front = 0, rear = 0;
    queue[rear++] = 1; 

    int current_level = 0;
    int nodes_in_current_level = 1;
    int nodes_in_next_level = 0;

    while (front < rear) {
        int node_index = queue[front++];
        nodes_in_current_level--;

        if (nodes[node_index].type == 1) {
            level_counts[current_level][0]++; 
        } else if (nodes[node_index].type == 2) {
            level_counts[current_level][1]++; 
        }

        if (nodes[node_index].left != 0) {
            queue[rear++] = nodes[node_index].left;
            nodes_in_next_level++;
        }
        if (nodes[node_index].right != 0) {
            queue[rear++] = nodes[node_index].right;
            nodes_in_next_level++;
        }

        if (nodes_in_current_level == 0) {
            current_level++;
            nodes_in_current_level = nodes_in_next_level;
            nodes_in_next_level = 0;
        }
    }

    for (int i = 1; i < current_level; i++) {
        if (level_counts[i][0] > 0 || level_counts[i][1] > 0) {
            printf("%d %d\n", level_counts[i][0], level_counts[i][1]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node nodes[n + 1]; 
    for (int i = 1; i <= n; i++) {
        int type, left, right;
        scanf("%d %d %d", &type, &left, &right);
        nodes[i].type = type;
        nodes[i].left = left;
        nodes[i].right = right;
    }

    bfs(nodes, n);

    return 0;
}