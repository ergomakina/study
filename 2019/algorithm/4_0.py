import networkx as nx
import random

list=[]

for i in range(1,11):
    list.append("random_"+str(i*1000)+".edgelist")

for i in range(0,10):
    G = nx.fast_gnp_random_graph((i+1)*1000,0.01)
    for (u,v) in G.edges():
        G.edges[u,v]['weight'] = random.randint(1,100)

    nx.write_weighted_edgelist(G,list[i])