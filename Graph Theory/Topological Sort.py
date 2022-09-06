V, E = [int(x) for x in input().split()]

vis = [False for i in range(V+1)]
adj = [[] for i in range(V+1)]
topological_sort = []

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    adj[u].append(v)

def dfs(u):
    vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            dfs(v)
    topological_sort.append(u)

for u in range(V):
    if not vis[u]:
        dfs(u)

topological_sort.reverse()
for u in topological_sort:
    print(u, end=" ")
