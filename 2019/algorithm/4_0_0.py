import networkx as nx
import time

G = nx.read_weighted_edgelist('dij.edgelist',nodetype=int)

D=[float('inf')] * nx.number_of_nodes(G)


def my_extract_min(D,X):
    arg_min = -1
    min_value = float('inf')

    for i in range (len(D)):
        if D[i] < min_value:
            if i in X:
                arg_min = i
                min_value = D[i]
    return arg_min


def my_Dijkstara(G,source):
    X=set(G.nodes)
    D=[float('inf')] * nx.number_of_nodes(G)
    D[source]=0
    
    while X:
        u=my_extract_min(D,X)
        X.remove(u)
        for v in G.neighbors(u):
            if v in X:
                new_distance=D[u]+G.edges[u,v]['weight']
                if D[v]>new_distance:
                    D[v]=new_distance
    return D

list=[]

for i in range(1,11):
    list.append("random_"+str(i*1000)+".edgelist")

for i in range(0,10):
    G = nx.read_weighted_edgelist(list[i],nodetype=int)
    start = time.time()
    D = my_Dijkstara(G,0)
    elapsed_time = time.time() - start
    print(list[i],":",elapsed_time,"\n")