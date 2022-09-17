#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> arr, nxt;

int main() {
	int n;
	cin >> n;
	arr.resize(n);
	nxt.resize(n, -1);
	stack<int> not_answered;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (!not_answered.empty() && arr[not_answered.top()] < arr[i]) {
			nxt[not_answered.top()] = i;
			not_answered.pop();
		}
		not_answered.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (nxt[i] != -1)
			cout << "Next greater element of " << arr[i] << " at position " << i << " is " << arr[nxt[i]] << " at position " << nxt[i] << endl;
		else {
			cout << "There is no greater element of " << arr[i] << " at position " << i << " after it" << endl;
		}
	}
}
