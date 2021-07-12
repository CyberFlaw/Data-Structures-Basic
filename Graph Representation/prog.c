#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph
{
    int V;
    int *indegreeArray;
    int *outdegreeArray;
    struct AdjList *array;
};

// A utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    graph->indegreeArray = (int *)malloc(V * sizeof(int));
    graph->outdegreeArray = (int *)malloc(V * sizeof(int));

    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNode *newNode = newAdjListNode(dest);
    graph->outdegreeArray[src]++;
    graph->indegreeArray[dest]++;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void printInAndOutDegree(struct Graph *graph, int a)
{
    printf("Indegree = %d\n", graph->indegreeArray[a]);
    printf("Outdegree = %d", graph->outdegreeArray[a]);
}

// Driver program to test above functions
int main()
{
    int v;
    // printf("Enter no of vertices - ");
    // scanf("%d", &v);

    struct Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
    printInAndOutDegree(graph, 3);

    return 0;
}
