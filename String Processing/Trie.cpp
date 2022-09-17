#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector< vector<int> > trie;
vector<bool> last;

void insert(string& s) {
	int node = 0; // starting node
	for (char c: s) {
		// assume all characters in all string in upper case
		int idx = c - 'A';
		int new_node = trie[node][idx];
		if (new_node == -1) {
			new_node = trie.size();
			trie.push_back(vector<int>(26, -1));
			last.push_back(false);
			trie[node][idx] = new_node;
		}
		node = new_node;
	}
	last[node] = true;
}

bool search(string& s) {
	int node = 0; // starting node
	for (char c : s) {
		// assume all characters in all string in upper case
		int idx = c - 'A';
		int new_node = trie[node][idx];
		if (new_node == -1) {
			return false;
		}
		node = new_node;
	}
	return last[node];
}

int main() {
	trie.push_back(vector<int>(26, -1));
	last.push_back(false);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (search(s)) {
			cout << "String " << s << " is found!" << endl;
		}
		else {
			cout << "String " << s << " is not found!" << endl;
		}
	}
}
