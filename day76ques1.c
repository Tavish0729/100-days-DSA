#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int visited[100];
int n, m;

void dfs(int node)
{
    visited[node] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}