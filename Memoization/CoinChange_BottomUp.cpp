#include <iostream>
#include <vector>
using namespace std;

int n, c;
vector<int> coins;
vector<int> dp;

int main() {
	cin >> n >> c;
	coins.resize(c);
	dp.resize(n + 1);

	// Reading coins
	for (int i = 0; i < c; i++)
		cin >> coins[i];

	// Initialization
	for (int i = 0; i <= n; i++)
		dp[i] = 1e9; // 10^9 (infinity)
	dp[0] = 0;

	// Bottom-Up calculation for all n values
	for (int i = 0; i <= n; i++) {
		// Iterating over all coins
		for (int coin : coins) {
			if (i + coin > n)
				continue;
			int previous = dp[i + coin];
			int possible_answer = dp[i] + 1;
			if (possible_answer < previous) {
				dp[i + coin] = dp[i] + 1;
			}
		}
	}

	// Printing answer
	int ans = dp[n];
	if (ans == 1e9)
		cout << "No answer!" << endl;
	else
		cout << dp[n] << endl;
}
