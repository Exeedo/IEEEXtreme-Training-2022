#include <iostream>
#include <vector>
using namespace std;

int n, c;
vector<int> coins;
vector<int> dp;

// Calculating in Top-Down approach
int solve(int n) {
	// Calculated before and saved
	if (dp[n] != -1)
		return dp[n];
	
	// Base case
	if (n == 0)
		return 0;

	int ans = 1e9; // 10^9 (infinity)
	for (int coin : coins) {
		int possible_ans = solve(n - coin) + 1;
		if (possible_ans < ans)
			ans = possible_ans;
	}

	// Don't forget to save your answer !
	dp[n] = ans; 
	return ans;
}

int main() {
	cin >> n >> c;
	coins.resize(c);
	dp.resize(n + 1);

	// Initialization
	for (int i = 0; i <= n; i++)
		dp[i] = -1;

	// Reading coins
	for (int i = 0; i < c; i++)
		cin >> coins[i];

	// Printing answer
	int ans = solve(n);
	if (ans == -1)
	    cout << "No answer!" << endl;
	else
	    cout << ans << endl;
}
