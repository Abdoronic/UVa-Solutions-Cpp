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
int arr[15];
ll memo[11][11];

ll dp(int i, int j) {
	if(i == j)
		return 0;
	if(memo[i][j] != -1) return memo[i][j];
	ll ans = LONG_MAX, cost;
	for(int k = i; k < j; k++) {
		cost = dp(i, k) + dp(k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, cost);
	}
	return memo[i][j] = ans;
}

string print(int i, int j) {
	if(i == j)
		return "A" + to_string(i);
	ll ans = dp(i, j), cost;
	for(int k = i; k < j; k++) {
		cost = dp(i, k) + dp(k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		if(cost == ans) {
			return "(" + print(i, k) + " x " + print(k + 1, j) + ")";
		}
	}
	return "";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tmp;
	for(int t = 1; true; t++) {
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n + 1; i++) {
			if(i == 0) {
				cin >> arr[i];
				++i;
				cin >> arr[i];
			}
			else {
				cin >> tmp >> arr[i];
			}
		}
		memset(memo, -1, sizeof memo);
		dp(1, n);
		printf("Case %d: %s\n", t, print(1, n).c_str());
	}
	return 0;
}
