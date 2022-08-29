#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<int> vis; // for cycle detection, 0:new, 1:under processing, 2:done
vector<vector<int>> adj;
bool cyclic_graph = false;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            dfs(v);
        }
        else if (vis[v] == 2) {
            continue;
        }
        else { // vis[1] == 1
            cyclic_graph = true;
        }
    }
    vis[u] = 2;
}

int main() {
    cin >> v >> e;
    vis.resize(v + 1);
    adj.resize(v + 1);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u); // for undirected graphs only
    }
    for (int i = 1; i <= v; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= v; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    if (cyclic_graph) {
        cout << "The graph is Cyclic! (contains a cycle)";
    }
    else {
        cout << "The graph is Acyclic! (does not contain a cycle)";
    }
}
