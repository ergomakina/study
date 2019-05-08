import networkx as nx

G = nx.read_weighted_edgelist(r'C:\Users\ergop\Documents\github\study\2019\algorithm\dij.edgelist',nodetype=int)

D = [float('inf')] * nx.number_of_nodes(G)

# print(G.edges())
# print(G.nodes[1, 2]['weight'])

# while X:
#     return 0


# D is an arrya
# X is a set
def my_extract_min(D, X):
    arg_min = -1
    min_value = float('inf')

    for i in range(len(D)):
        if D[i] < min_value:
            if i in X:
                arg_min = i
                min_value = D[i]
    
    return arg_min

# 始点から各点への最短経路長を出力する関数
def get_length(G,start):

    return length

import matplotlib.pyplot as plt
# グラフの描画
# nx.draw_networkx(G)
# 表示
# plt.show()

# display the graph
node_list = G.nodes()
print("node_list: " , node_list)

# 訪問済みノード
target_nodes = set()