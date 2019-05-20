import networkx as nx
import heapq, time

def my_extract_min2(D,X):
    Q=[]
    for i in X:
        heapq.heappush(Q,(D[i],i))
    min_value, argmin_index = heapq.heappop(Q)   
    return argmin_index       

def my_Dijikstara2(G,source):
    X=set(G.nodes)
    D=[float('inf')] * nx.number_of_nodes(G)
    D[source]=0
    
    while X:
        Q=[]
        u=my_extract_min2(D,X)
        X.remove(u)
        for v in G.neighbors(u):
            if v in X:
                heapq.heappush(Q,(D[v],v))
                new_distance=D[u]+G.edges[u,v]['weight']
                heapq.heappush(Q,(new_distance,v))
                min_value, argmin_index=heapq.heappop(Q)
                D[v]=min_value

        
    return D

def my_Dijikstra2(G,source):
    X=set(G.nodes)
    D=[float('inf')] * nx.number_of_nodes(G)
    D[source]=0
    # print(D)
    Q=[]
    h.heappush(Q,(0,source))#初期位置ヒープ
    
    
    while X:
        min_value , argmin_index =h.heappop(Q)
        if min_value>D[argmin_index]:
            continue
        X.remove(argmin_index)
        for v in G.neighbors(argmin_index):
            if v in X:
                new_distance=D[argmin_index]+G.edges[argmin_index,v]['weight']
                if D[v]>new_distance:
                    h.heappush(Q,((new_distance),v))
                    D[v]=new_distance
                    
                    
    return D
        


list=[]

for i in range(1,11):
    list.append("random_"+str(i*1000)+".edgelist")

for i in range(0,10):
    G = nx.read_weighted_edgelist(list[i],nodetype=int)
    start = time.time()
    D = my_Dijikstara2(G,0)
    elapsed_time = time.time() - start
    print(list[i],":",elapsed_time,"\n")