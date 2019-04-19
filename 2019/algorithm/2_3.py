# import libraries
import networkx as nx

# load the data of a graph
# G = nx.read_edgelist(r'C:\Users\ergop\Documents\Development\GitHub\study\2019\algorithm\test.edgelist',nodetype=int)
G = nx.read_edgelist(r'C:\Users\ergop\Documents\github\study\2019\algorithm\test.edgelist',nodetype=int)

# G = nx.gnm_random_graph(10,16)

def trail(graph):
    for i in graph.degree:
        if i[1] % 2 != 0:
            return False
    return True



print(trail(G))
print(G.edges())

import matplotlib.pyplot as plt
nx.draw_networkx(G)
plt.show()