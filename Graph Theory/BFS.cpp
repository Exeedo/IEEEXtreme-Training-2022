#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // for queue and priority queue
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> dist;

void traversal(int s) {
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1; // for unweighted graph
				q.push(v);
			}
		}
	}
}

int main() {
	cin >> V >> E;
	adj.resize(V+1);
	dist.resize(V+1);
	for (int i = 1; i <= V; i++)
		dist[i] = -1;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w; // weight is not used for BFS
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	traversal(1);
	for (int i = 1; i <= V; i++)
		cout << "dist of " << i << " = " << dist[i] << endl;
}
