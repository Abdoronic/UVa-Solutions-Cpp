#include "bits/stdc++.h"

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

int n, q, hours;
int flow[25];
int cost[25];

int solve(int i, int vol) {
	if(i == n || vol <= 0) {
		if(vol <= 0)
			return 0;
		return INF;
	}
	int ans = INF;
	ans = min(ans, cost[i] + solve(i+1, vol - flow[i]*hours));
	ans = min(ans, solve(i+1, vol));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> flow[i] >> cost[i];
	cin >> q;
	int vol;
	for(int i = 1; q--; i++) {
		cin >> vol >> hours;
		int ans = solve(0, vol);
		cout << "Case " << i << ": ";
		if(ans >= INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
	}
	return 0;
}
