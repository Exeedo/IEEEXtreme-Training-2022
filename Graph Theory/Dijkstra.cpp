#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // for queue and priority queue
using namespace std;

int V, e;
vector<vector<pair<int,int>>> adj; // pair: node number, weight
vector<int> dist;

void traversal(int s) {
	dist[s] = 0;
	priority_queue<pair<int, int>> q; // pair: distance, node number
	q.push({ 0,s });
	while (!q.empty()) {
		int u = q.top().second;
		int d = q.top().first * -1;
		q.pop();
		if (d > dist[u])
			continue;
		for (auto p : adj[u]) {
			int v = p.first;
			int w = p.second;
			int new_dist = dist[u] + w;
			if (dist[v] == -1) { // for new nodes
				dist[v] = new_dist; // for weighted graph
				q.push({ -1*dist[v], v });
			}
			else if (dist[v] > new_dist) {
				dist[v] = new_dist;
				q.push({ -1 * dist[v], v });
			}
		}
	}
}

int main() {
	cin >> V >> e;
	adj.resize(V+1);
	dist.resize(V+1);
	for (int i = 1; i <= V; i++)
		dist[i] = -1;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	traversal(1);
	for (int i = 1; i <= V; i++)
		cout << "dist of " << i << " = " << dist[i] << endl;
}
