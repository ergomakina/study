/* grpah.c */

#include <stdlib.h>
#include "queue.h"
#include "graph.h"

typedef struct Edge
{
    struct Node *node;
    struct Edge *next;
} Edge;

typedef struct Node
{
    NodeType value;
    int visited;
    Edge *edges;
} Node;

Graph *graph_construct()
{
    Node *nodes = (Node *)malloc(sizeof(Node) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        nodes[i].value = 0;
        nodes[i].edges = NULL;
    }
    return (Graph *)nodes;
}

void graph_free_edge(Edge *edge)
{
    if (edge != NULL)
    {
        graph_free_edge(edge->next);
        free(edge);
    }
}

void graph_free(Graph *graph)
{
    Node *nodes = (Node *)graph;
    for (int i = 0; i < SIZE; i++)
    {
        graph_free_edge(nodes[i].edges);
    }
    free(nodes);
}

void graph_set_value(Graph *graph, int index, NodeType value)
{
    Node *nodes = (Node *)graph;
    nodes[index].value = value;
}

void graph_add_edge(Graph *graph, int from, int to)
{
    Node *nodes = (Node *)graph;
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->next = NULL;
    edge->node = &nodes[to];
    if (nodes[from].edges == NULL)
    {
        nodes[from].edges = edge;
    }
    else
    {
        Edge *tail = nodes[from].edges;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = edge;
    }
}

void graph_dfs_inner(Node *node, Visitfn f)
{
    /* Fill in here.*/
    // 隣接リスト　深さ優先探索
    node->visited = 1;
    f(node->value);
    // graph_dfs_inner(node->edges->next, f);
    Edge *edge = node->edges;
    while (edge != NULL)
    {
        if (!edge->node->visited)
        {
            graph_dfs_inner(edge->node, f);
        }
    }
}

void graph_dfs(Graph *graph, int start, Visitfn f)
{
    Node *nodes = (Node *)graph;
    for (int i = 0; i < SIZE; i++)
    {
        nodes[i].visited = 0;
    }

    graph_dfs_inner(&nodes[start], f);
}

void graph_bfs(Graph *graph, int start, Visitfn f)
{
    //隣接リスト　幅優先探索
    Node *nodes = (Node *)graph;
    for (int i = 0; i < SIZE; i++)
    {
        nodes[i].visited = 0;
    }

    QUEUE queue = queue_construct();

    /* Fill in here */
    nodes->visited = 1;
    f(nodes->value);
    queue_enqueue(queue, (T)start);
    while (!queue_empty(queue))
    {

        f(nodes->edges->node->value);
        nodes->edges->next
    }

    queue_free(queue);
}