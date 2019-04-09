/* graph.h */

#define SIZE 100

typedef int NodeType;
typedef void* Graph;
typedef void (*Visitfn)(NodeType value);

Graph* graph_construct();
void graph_free(Graph* graph);

void graph_set_value(Graph* graph, int index, NodeType value);
void graph_add_edge(Graph* graph, int from, int to);
void graph_dfs(Graph* graph, int start, Visitfn f);
void graph_bfs(Graph* graph, int start, Visitfn f);