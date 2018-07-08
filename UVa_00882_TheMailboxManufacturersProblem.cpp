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

int memo[11][101][101];

int dp(int k, int lo, int hi) {
	if(k == 1)
		return hi * (hi + 1) / 2 - (lo - 1) * lo / 2;
	if(lo == hi) return lo;
	if(memo[k][lo][hi] != -1) return memo[k][lo][hi];
	int ans = INF, curr;
	for(int i = lo + 1; i < hi; i++) {
		curr = max(i + dp(k - 1, lo, i - 1), i + dp(k, i + 1, hi));
		ans = min(ans, curr);
	}
	ans = min(ans, lo + dp(k, lo + 1, hi));
	ans = min(ans, hi + dp(k - 1, lo, hi - 1));
	return memo[k][lo][hi] = ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, k, m;
	cin >> tc;
	while(tc--) {
		cin >> k >> m;
		memset(memo, -1, sizeof memo);
		cout << dp(k, 1, m) << '\n';
	}
	return 0;
}
