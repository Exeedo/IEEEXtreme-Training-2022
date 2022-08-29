#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<int> topological_sort;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    topological_sort.push_back(u);
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
    reverse(topological_sort.begin(), topological_sort.end());
    for (int i : topological_sort) {
        cout << i << " ";
    }
}
