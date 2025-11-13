
INF = 9999999 
# Number of vertices in the graph 
V = 6 
# Graph as an adjacency matrix:: 0 means no edge 
G = [ 
[0, 4, 0, 0, 0, 2], 
[4, 0, 6, 0, 0, 3], 
[0, 6, 0, 3, 0, 1], 
[0, 0, 3, 0, 2, 0], 
[0, 0, 0, 2, 0, 4], 
[2, 3, 1, 0, 4, 0] 
] 
# To track visited vertices 
selected = [False] * V 
# Initially no edge is selected 
no_edge = 0 
# Start from the first vertex 
selected[0] = True 
# Store total weight of MST 
total_weight = 0 
print("Edge : Weight\n") 
while no_edge < V - 1: 
 minimum = INF 
 x = 0 
 y = 0 
 for i in range(V): 
     if selected[i]: 
        for j in range(V): 
            if (not selected[j]) and G[i][j]: 
 # If smaller edge is found 
               if minimum > G[i][j]: 
                  minimum = G[i][j] 
                  x = i 
                  y = j 
 print(f"{x} - {y} : {G[x][y]}") 
 total_weight += G[x][y] # add weight of selected edge 
 selected[y] = True 
 no_edge += 1 
print("\nTotal weight of Minimum Spanning Tree =", total_weight) 