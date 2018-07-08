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
int leftPoint[20001], rightPoint[20001];
int memo[2][20001];

int dp(int isLeft, int idx) {
	int ans = INF, cost = rightPoint[idx] - leftPoint[idx];
	if(idx == n - 1) {
		if(isLeft)
			return cost + abs(n - 1 - rightPoint[idx]);
		return cost + abs(n - 1 - leftPoint[idx]);
	}
	if(memo[isLeft][idx] != -1) return memo[isLeft][idx];
	if(idx == 0) {
		cost = rightPoint[idx];
		ans = min(ans, cost + abs(rightPoint[idx] - leftPoint[idx + 1]) + 1 + dp(1, idx + 1));
		ans = min(ans, cost + abs(rightPoint[idx] - rightPoint[idx + 1]) + 1 + dp(0, idx + 1));
	} else {
		if(isLeft) {
			ans = min(ans, cost + abs(rightPoint[idx] - leftPoint[idx + 1]) + 1 + dp(1, idx + 1));
			ans = min(ans, cost + abs(rightPoint[idx] - rightPoint[idx + 1]) + 1 + dp(0, idx + 1));
		} else {
			ans = min(ans, cost + abs(leftPoint[idx] - leftPoint[idx + 1]) + 1 + dp(1, idx + 1));
			ans = min(ans, cost + abs(leftPoint[idx] - rightPoint[idx + 1]) + 1 + dp(0, idx + 1));
		}
	}
	return memo[isLeft][idx] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true) {
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++) {
			cin >> leftPoint[i] >> rightPoint[i];
			leftPoint[i]--;
			rightPoint[i]--;
		}
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0) << '\n';
	}
	return 0;
}
