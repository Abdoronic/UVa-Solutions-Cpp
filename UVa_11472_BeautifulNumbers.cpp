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

int n, m;
ll memo[101][11][1 << 10];

ll dp(int idx, int pre, int msk) {
	if(idx == m) {
		if(msk == ((1 << n) - 1))
			return 1;
		return 0;
	}
	if(memo[idx][pre][msk] != -1) return memo[idx][pre][msk];
	ll ans = msk == ((1 << n) - 1);
	for(int i = 0; i < n; i++) {
		if(pre == 10 && i != 0)
			ans += dp(idx + 1, i, msk | (1 << i)) % MOD;
		else if(abs(pre - i) == 1)
			ans += dp(idx + 1, i, msk | (1 << i)) % MOD;
		ans = ans % MOD;
	}
	return memo[idx][pre][msk] = ans % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> n >> m;
		memset(memo, -1, sizeof memo);
		cout << dp(0, 10, 0) << '\n';
	}
	return 0;
}
