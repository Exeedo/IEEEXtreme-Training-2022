#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	// structure to indicate that there is an edge from u to v with a w weight (possibly negative)
	// You can use a tuple with 3 elements as well
	int u;
	int v;
	long long w;
};

long long INF = 1e18; // ** usually more than the maximum possible 

int V, E; // number of vertices and edges in the graph
vector<edge> edges;
vector<long long> dist;
vector<int> par;

bool relaxation(edge e) {
	if (dist[e.v] > dist[e.u] + e.w) {
		dist[e.v] = dist[e.u] + e.w;
		par[e.v] = e.u;
		return true;
	}
	return false;
}

void bellman_ford(int source) {
	dist[source] = 0;
	par[source] = -1; // source node has no parent node
	bool modified;
	for (int i = 0; i < V - 1; i++) {
		modified = false;
		for (edge e : edges) {
			if (relaxation(e)) {
				modified = true;
			}
		}
		if (!modified)
			break; // early stopping criteria (for optimization purposes)
	}
	modified = false;
	for (edge e : edges) {
		if (relaxation(e)) {
			modified = true;
			break;
		}
	}
	if (modified) {
		cout << "A negative weighted cycle is detected!" << endl;
		cout << "Cannot find minimum distances in this case." << endl;
		exit(0);
	}
}

int main() {
	cin >> V >> E;
	dist.resize(V + 1);
	par.resize(V + 1);
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	// Reading input for directed graphs
	edges.resize(E);
	for (int i = 0; i < E; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
	}
	/*
	// Reading input for undirected graphs
	edges.resize(2 * E);
	for (int i = 0; i < 2 * E; i += 2) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		// Saving edge from u to v
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
		// Saving edge from v to u
		edges[i].u = v;
		edges[i].v = u;
		edges[i].w = w;
	}
	*/
	bellman_ford(1); // Source is node 1
	for (int i = 1; i <= V; i++)
		cout << "dist of " << i << " = " << dist[i] << endl;
}
