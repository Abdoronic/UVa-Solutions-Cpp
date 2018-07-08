#include <bits/stdc++.h>

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

int n;
string s;
ll memo[201];

ll dp(int idx) {
	if(idx == n)
		return 0;
	if(memo[idx] != -1) return memo[idx];
	ll ans = 0, sum = 0;
	for(int i = idx; i < n; i++) {
		sum = sum * 10 + s[i] - '0';
		if(sum > INT_MAX) break;
		ans = max(ans, sum + dp(i + 1));
	}
	return memo[idx] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> s;
		n = s.length();
		memset(memo, -1, sizeof memo);
		cout << dp(0) << '\n';
	}
	return 0;
}
