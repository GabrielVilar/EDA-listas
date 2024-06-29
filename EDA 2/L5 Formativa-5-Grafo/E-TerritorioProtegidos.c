#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

typedef long long ll;

int N, M;
int visited[MAXN];
int territory_id[MAXN];
ll territory_cost[MAXN];
int current_territory;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* graph[MAXN];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = graph[u];
    graph[u] = newNode;
    
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = graph[v];
    graph[v] = newNode;
}

void DFS(int u) {
    visited[u] = 1;
    territory_id[u] = current_territory;
    territory_cost[current_territory] |= (ll)u;
    
    Node* temp = graph[u];
    while (temp != NULL) {
        int v = temp->data;
        if (!visited[v]) {
            DFS(v);
        }
        temp = temp->next;
    }
}

void findTerritories() {
    current_territory = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            current_territory++;
            territory_cost[current_territory] = 0;
            DFS(i);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; ++i) {
        graph[i] = NULL;
        visited[i] = 0;
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    findTerritories();
    
    ll final_price = 0;
    for (int i = 1; i <= current_territory; ++i) {
        final_price ^= territory_cost[i];
    }
    
    printf("%lld\n", final_price);
    
    return 0;
}