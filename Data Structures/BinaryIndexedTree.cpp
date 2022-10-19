#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector <int> arr, BIT;

int LeastSignificantOne(int x) {
	return x & (-x);
}

int get(int x) { // retrieve sum of indices from 1 to x
	int sum = 0;
	for (int i=x; i > 0; i -= LeastSignificantOne(i)) {
		sum += BIT[i];
	}
	return sum;
}

void update(int x, int update_value) { // update the index x by update_value -> arr[x] += new_value
	for (int i = x; i <= n; i += LeastSignificantOne(i)) {
		BIT[i] += update_value;
	}
}

int main() {
	cin >> n >> q;
	arr.resize(n + 1);
	BIT.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]); // build process is done by updating each element with its initial value
	}
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		// type = 1 -> input: L,R -> output: Q[L,R], retrieve query
		// type = 2 -> input: x,new value -> no output, update query
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << get(r) - get(l - 1) << endl;
		}
		else if (type == 2) {
			int x, update_value;
			cin >> x >> update_value;
			update(x, update_value);
		}
	}
}
