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
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	stack<int> nxt_stack;
	nxt_stack.push(n - 1); // adding last element to the stack
	for (int i = n - 2; i >= 0; i--) {
		while (!nxt_stack.empty() && arr[nxt_stack.top()] < arr[i])
			nxt_stack.pop();

		if (!nxt_stack.empty())
			nxt[i] = nxt_stack.top();
		nxt_stack.push(i);
	}
	for (int i = 0; i < n; i++) {
		if (nxt[i] != -1)
			cout << "Next greater element of " << arr[i] << " at position " << i << " is " << arr[nxt[i]] << " at position " << nxt[i] << endl;
		else {
			cout << "There is no greater element of " << arr[i] << " at position " << i << " after it" << endl;
		}
	}
}
