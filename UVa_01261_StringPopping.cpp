#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back

#define INF int(1e9)
#define EPS 1e-9
#define MOD int(1e9 + 7)

unordered_map<string, bool> memo;

inline string cut(string s, int i, int j) {
	return s.substr(0, i) + s.substr(j + 1, s.length() - j + 1);
}

bool dp(string word) {
	if(word.length() == 0) return true;
	if(memo.find(word) != memo.end()) return memo[word];
	bool ans = false;
	for(int i = 0, j; i < word.length(); i++) {
		char c = word[i];
		for(j = i; j < word.length() && word[j] == c; j++);
		if(word[j] != c) j--;
		if(j > i)
			ans |= dp(cut(word, i, j));
	}
	memo.insert({word, ans});
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	string word;
	cin >> tc;
	while(tc--) {
		cin >> word;
		memo.clear();
		cout << dp(word) << '\n';
	}
	return 0;
}
