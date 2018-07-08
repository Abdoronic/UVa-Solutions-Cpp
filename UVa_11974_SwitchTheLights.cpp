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
int arr[105];
int memo[105][1 << 16];

int dp(int idx, int msk) {
	if(idx == m) {
		if(msk == (1 << n) - 1)
			return 0;
		return INF;
	}
	if(memo[idx][msk] != -1) return memo[idx][msk];
	int ans = INF;
	ans = min(ans, dp(idx + 1, msk));
	ans = min(ans, 1 + dp(idx + 1, msk ^ arr[idx]));
	return memo[idx][msk] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	for(int t = 1; tc--; t++) {
		cin >> n >> m;
		string s;
		char c;
		for(int i = 0; i < m; i++) {
			s = "";
			for(int j = 0; j < n; j++) {
				cin >> c;
				s += c;
			}
			arr[i] = stoi(s, nullptr, 2);
		}
		memset(memo, -1, sizeof memo);
		int ans = dp(0, 0);
		if(ans == INF)
			printf("Case %d: IMPOSSIBLE\n", t);
		else
			printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
