#include <stdio.h>
#include <stdlib.h>

int *a, *q, *visited, n, i, j, f = 0, r = -1;

void dfs(int v)
{
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (a[(v)*n + i] == 1 && visited[i] == 0)
            dfs(i);
}	

void insert_queue(int vertex)
{
    if (f == -1)
        f = 0;
    r = r + 1;
    q[r] = vertex;
}
int isEmpty_queue()
{
    if (f == -1 || f > r)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if (f == -1 || f > r)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = q[f];
    f = f + 1;
    return delete_item;
}

void bfs(int v)
{
    insert_queue(v);

    while (!isEmpty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        visited[v] = 1;

        for (i = 0; i < n; i++)
        {
            if (a[v * n + i] && !visited[i])
            {
                insert_queue(i);
            }
        }
    }
    printf("\n");
}

void main()
{
    int v;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    if (n < 1)
        exit;

    a = (int *)malloc(n * n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));
    q = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("Enter the Adjacency Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Row %d\n", i + 1);
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i * n + j]);
    }

    printf("\nBFS\n");
    bfs(0);

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS\n");
    dfs(0);
}

