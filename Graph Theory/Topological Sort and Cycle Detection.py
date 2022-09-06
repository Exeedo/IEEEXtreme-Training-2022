V, E = [int(x) for x in input().split()]

vis = [0 for i in range(V+1)]
adj = [[] for i in range(V+1)]
cyclic_graph = False
topological_sort = []

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    adj[u].append(v)

def dfs(u):
    vis[u] = 1
    for v in adj[u]:
        if vis[v] == 0:
            dfs(v)
        elif vis[v] == 2:
            continue
        else: # vis[v] == 1
            cyclic_graph = True
    topological_sort.append(u)
    vis[u] = 2

for u in range(V):
    if not vis[u]:
        dfs(u)

if cyclic_graph:
    print("No valid topological sort, the graph is cyclic!")
else:
    topological_sort.reverse()
    for u in topological_sort:
        print(u, end=" ")
