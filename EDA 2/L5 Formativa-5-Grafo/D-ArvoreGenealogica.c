#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 300
#define MAX_NAME_LEN 50

// Adjacency list node
struct Node {
    int person;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numPeople;
    struct Node** adjLists;
    int* visited;
};

// Function to create a node
struct Node* createNode(int person) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->person = person;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int numPeople) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numPeople = numPeople;
    graph->adjLists = malloc(numPeople * sizeof(struct Node*));
    graph->visited = malloc(numPeople * sizeof(int));
    for (int i = 0; i < numPeople; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function to traverse the graph
void DFS(struct Graph* graph, int person) {
    graph->visited[person] = 1;
    struct Node* adjList = graph->adjLists[person];
    struct Node* temp = adjList;

    while (temp != NULL) {
        int connectedPerson = temp->person;
        if (!graph->visited[connectedPerson]) {
            DFS(graph, connectedPerson);
        }
        temp = temp->next;
    }
}

// Function to find the index of a person in the names array
int findPersonIndex(char names[MAX_PEOPLE][MAX_NAME_LEN], int numPeople, char* name) {
    for (int i = 0; i < numPeople; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    struct Graph* graph = createGraph(M);
    char names[MAX_PEOPLE][MAX_NAME_LEN];
    int numPeople = 0;

    for (int i = 0; i < N; i++) {
        char name1[MAX_NAME_LEN], relation[MAX_NAME_LEN], name2[MAX_NAME_LEN];
        scanf("%s %s %s", name1, relation, name2);

        int index1 = findPersonIndex(names, numPeople, name1);
        if (index1 == -1) {
            strcpy(names[numPeople], name1);
            index1 = numPeople;
            numPeople++;
        }

        int index2 = findPersonIndex(names, numPeople, name2);
        if (index2 == -1) {
            strcpy(names[numPeople], name2);
            index2 = numPeople;
            numPeople++;
        }

        addEdge(graph, index1, index2);
    }

    int numFamilies = 0;
    for (int i = 0; i < M; i++) {
        if (!graph->visited[i]) {
            DFS(graph, i);
            numFamilies++;
        }
    }

    printf("%d\n", numFamilies);

    return 0;
}