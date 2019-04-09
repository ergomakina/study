/* matrix_graph.c */

#include <stdlib.h>
#include "queue.h"
#include "graph.h"

typedef struct MGraph
{
    NodeType values[SIZE];
    int visited[SIZE];
    int matrix[SIZE][SIZE];
} MGraph;

Graph *graph_construct()
{
    MGraph *mgraph = (MGraph *)malloc(sizeof(MGraph));
    for (int i = 0; i < SIZE; i++)
    {
        mgraph->values[i] = 0;
        for (int j = 0; j < SIZE; j++)
        {
            mgraph->matrix[i][j] = 0;
        }
    }
    return (Graph *)mgraph;
}

void graph_free(Graph *graph)
{
    MGraph *mgraph = (MGraph *)graph;
    free(mgraph);
}

void graph_set_value(Graph *graph, int index, NodeType value)
{
    MGraph *mgraph = (MGraph *)graph;
    mgraph->values[index] = value;
}

void graph_add_edge(Graph *graph, int from, int to)
{
    MGraph *mgraph = (MGraph *)graph;
    mgraph->matrix[from][to] = 1;
}

void graph_dfs_inner(MGraph *mgraph, int index, Visitfn f)
{
    mgraph->visited[index] = 1; //訪問済みチェック
    f(mgraph->values[index]);

    for (int i = 0; i < SIZE; i++)
    {
        if (mgraph->matrix[index][i])
        { //隣接する未訪問ノードに対して再帰
            if (!mgraph->visited[i])
            {
                graph_dfs_inner(mgraph, i, f);
            }
        }
    }
}

void graph_dfs(Graph *graph, int start, Visitfn f)
{
    MGraph *mgraph = (MGraph *)graph;
    for (int i = 0; i < SIZE; i++)
    {
        mgraph->visited[i] = 0;
    }

    graph_dfs_inner(mgraph, start, f);
}

void graph_bfs(Graph *graph, int start, Visitfn f)
{
    MGraph *mgraph = (MGraph *)graph;
    for (int i = 0; i < SIZE; i++)
    {
        mgraph->visited[i] = 0;
    }

    QUEUE queue = queue_construct();

    mgraph->visited[start] = 1;
    f(mgraph->values[start]);
    queue_enqueue(queue, (T)start);
    while (!queue_empty(queue))
    {
        int index = (int)queue_dequeue(queue);

        for (int i = 0; i < SIZE; i++)
        {
            if (mgraph->matrix[index][i])
            {
                if (!mgraph->visited[i])
                {
                    mgraph->visited[i] = 1;
                    f(mgraph->values[i]);
                    queue_enqueue(queue, (T)i);
                }
            }
        }
    }

    queue_free(queue);
}