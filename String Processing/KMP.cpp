#include <iostream>
#include <vector>
using namespace std;

string s, t;
vector<int> fail;

/*
012345678901234567890123456789012345
abcabcdabcabcabcabcabcdabcabcabcabcd <- S
abcabcd <- T
0001230 <- Fail array
*/
int main() {
	cin >> s >> t;
	fail.resize(t.size());
	fail[0] = 0;
	// fill fail array:
	int match = 0;
	for (int i = 1; i < t.size(); i++) {
		while (match > 0 && t[i] != t[match]) {
			match = fail[match - 1];
		}
		if (t[i] == t[match])
			match++;
		fail[i] = match;
	}

	for (int x : fail)
		cout << x << ' ';
	cout << endl;

	// search for t in s:
	match = 0;
	for (int i = 0; i < s.size(); i++) {
		while (match>0 && s[i] != t[match]) {
			match = fail[match - 1];
		}
		if (s[i] == t[match])
			match++;
		if (match == t.size()) {
			cout << "Found match at index " << i - match + 1 << endl;
			match = fail.back();	// allowing overlap between matches
			// match = 0;			// not allowing overlap
		}
	}
}
