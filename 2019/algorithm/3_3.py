import networkx as nx
import matplotlib.pyplot as plt

G = nx.read_weighted_edgelist(r'dij.edgelist',nodetype=int)
D = [float('inf')] * nx.number_of_nodes(G)

def my_extract_min(D, X):
    arg_min = -1
    min_value = float('inf')
    for i in range(len(D)):
        if D[i] < min_value:
            if i in X:
                arg_min = i
                min_value = D[i]
    return arg_min

def my_Dijkstra(G, source):
    X = set(G.nodes)
    D = [float('inf')] * nx.number_of_nodes(G)
    D[source] = 0

    while X:
        u = my_extract_min(D, X)
        X.remove(u)
        for v in G.neighbors(u):
            if v in X:
                new_distance = D[u] + G.edges[u, v]['weight']
                if D[v] > new_distance:
                    D[v] = new_distance
    return D

print(my_Dijkstra(G, 0))
