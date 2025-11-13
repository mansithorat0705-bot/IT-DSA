
G=[
    [0,4,0,0,0,2],
    [4,0,6,0,0,3],
    [0,6,0,3,0,1],
    [0,0,3,0,2,0],
    [0,0,0,2,0,4],
    [2,3,1,0,4,0]
]
V=len(G)

edges=[]
for i in range(V):
    for j in range(i+1,V):
        if G[i][j]!=0:
            edges.append((G[i][j],i,j))
edges.sort()

parent=[i for i in range(V)]

def find(v):
    while parent[v]!=v:
        v=parent[v];
    return v
    
def union(u,v):
    root_u=find(u)
    root_v=find(v)
    if root_u!=root_v:
        parent[root_v]=root_u

mst_edges=[]
mst_weight=0

print("edges:weight")
for weight,u,v in edges:
    if find(u)!=find(v):
        union(u,v)
        mst_edges.append((u,v,weight))
        mst_weight+=weight
        
print("result:")
for u,v,w in mst_edges:
    print(f"{u}-{v}:{w}")
print("total weight of minimum spanning tree=",mst_weight)

    
