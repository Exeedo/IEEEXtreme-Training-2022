#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 17;
int inf = 1e9;
int arr[N];
int seg[N*4];
bool lazy[N * 4];

void build(int node_idx, int node_start, int node_end) {
	if (node_start == node_end) { // leaf node
		seg[node_idx] = arr[node_start];
		return;
	}
	int md = (node_start + node_end) / 2;
	build(node_idx*2, node_start, md); // left child
	build(node_idx * 2+1, md+1, node_end); // right child
}

void propagate(int node_idx) {
	seg[node_idx * 2] = seg[node_idx];
	seg[node_idx * 2+1] = seg[node_idx];

	lazy[node_idx * 2] = true;
	lazy[node_idx * 2 + 1] = true;
}

int get(int node_idx, int node_start, int node_end, int query_left, int query_right) {
	if (node_start >= query_left && node_end <= query_right) { // node is completely inside the range
		return seg[node_idx];
	}
	if (node_start > query_right || node_end < query_left) { // node is completely outside the range
		return inf;
	}
	if (lazy[node_idx]) {
		propagate(node_idx);
	}
	lazy[node_idx] = false;
	int md = (node_start + node_end) / 2;
	int min_left = get(node_idx * 2, node_start, md, query_left, query_right); // left child
	int min_right = get(node_idx * 2 + 1, md + 1, node_end, query_left, query_right); // right child
	return min(min_left, min_right);
}

void update_range(int node_idx, int node_start, int node_end, int query_left, int query_right, int update_value) {
	if (lazy[node_idx] && node_start != node_end) {
		propagate(node_idx);
	}
	lazy[node_idx] = false;
	if (node_start >= query_left && node_end <= query_right) { // node is completely inside the range
		seg[node_idx] = update_value;
		lazy[node_idx] = true;
		return;
	}
	if (node_start > query_right || node_end < query_left) { // node is completely outside the range
		return;
	}
	int md = (node_start + node_end) / 2;
	update_range(node_idx * 2, node_start, md, query_left, query_right, update_value); // left branch
	update_range(node_idx * 2 + 1, md + 1, node_end, query_left, query_right, update_value); // right branch
	seg[node_idx] = min(seg[node_idx * 2], seg[node_idx * 2 + 1]);
}


void update_one_value(int node_idx, int node_start, int node_end, int update_index, int update_value) {
	if (node_start == node_end) { // leaf node
		if (node_start == update_index) {
			arr[update_index] = update_value; // updating the original array (optional)
			seg[node_idx] = update_value; // required
		}
		return;
	}
	if (update_index < node_start || update_index > node_end) {
		return;
	}
	int md = (node_start + node_end) / 2;
	update_one_value(node_idx * 2, node_start, md, update_index, update_value); // update the left branch
	update_one_value(node_idx * 2 + 1, md + 1, node_end, update_index, update_value); // update the right branch
	seg[node_idx] = min(seg[node_idx * 2], seg[node_idx * 2 + 1]);
}



int main() {
	int n, q;
	cin >> n; // 16
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(1, 1, n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << get(1, 1, n, l, r) << endl;
	}
}
