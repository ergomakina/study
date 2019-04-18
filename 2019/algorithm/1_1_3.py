# import libraries
import networkx as nx
import matplotlib.pyplot as plt

# load the data of a graph
G = nx.read_edgelist(r'C:\Users\ergop\Documents\Development\GitHub\study\2019\algorithm\test.edgelist',nodetype=int)

# display the graph
node_list = G.nodes()
print("node_list: " , node_list)

# 訪問済みノード
visited_nodes = set()

# ノードを受け取ったらそのノードを起点に探索していく再帰
def depth(node,node_set,visited_set):
    for v in node_set.neighbors(node):
        if v not in visited_set:
            visited_set.add(v)
            print(v)
            depth(v,node_set,visited_set)

node = 4
visited_nodes.add(node)
depth(node,G,visited_nodes)

print(visited_nodes)
