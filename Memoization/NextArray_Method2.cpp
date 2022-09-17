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

	for (int i = n - 2; i >= 0; i--) {
		int ans = i + 1;
		while (ans != -1 && arr[ans] < arr[i])
			ans = nxt[ans];
		nxt[i] = ans;
	}
	for (int i = 0; i < n; i++) {
		if (nxt[i] != -1)
			cout << "Next greater element of " << arr[i] << " at position " << i << " is " << arr[nxt[i]] << " at position " << nxt[i] << endl;
		else {
			cout << "There is no greater element of " << arr[i] << " at position " << i << " after it" << endl;
		}
	}
}
