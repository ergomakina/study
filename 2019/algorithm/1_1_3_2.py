# import libraries
import networkx as nx
import matplotlib.pyplot as plt

# load the data of a graph
G = nx.read_edgelist(r'C:\Users\ergop\Documents\github\study\2019\algorithm\test.edgelist',nodetype=int)

# display the graph
print(G.nodes())

for v in G.neighbors(0):
    print(v)