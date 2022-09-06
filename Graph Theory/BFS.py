def traversal(s):
    idx = 0
    queue = []
    queue.append(s)
    dist[source] = 0
    while idx < len(queue): # equivalent to while(!q.empty())
        u = queue[idx]      # equivalent to queue.front()
        idx += 1            # equivalent to pop()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                queue.append(v)

V, E = [int(x) for x in input().split()]
dist = [-1 for _ in range(V+1)]
adj = [[] for _ in range(V+1)]
for _ in range(E):
    u, v, w = [int(x) for x in input().split()] # weight is not used for BFS
    adj[u].append(v)
    adj[v].append(u)

traversal(1)

for i in range(1,n+1):
    print(f"dist of {i} = {dist[i]}")
