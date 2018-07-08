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
int x[16], y[16];
double memo[1 << 16];

double dist(int i, int j) {
	return hypot(x[i] - x[j], y[i] - y[j]);
}

double dp(int msk) {
	if(msk == (1 << n) - 1)
		return 0;
	if(memo[msk] > -5) return memo[msk];
	double ans = INF;
	int i = 0;
	for(; i < n; i++)
		if((msk & (1 << i)) == 0) break;
	msk |= (1 << i);
	for(int j = 0; j < n; j++)
		if((msk & (1 << j)) == 0)
			ans = min(ans, dist(i, j) + dp(msk | (1 << j)));
	return memo[msk] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string tmp;
	for(int t = 1; true; t++) {
		cin >> n;
		if(n == 0) break;
		n *= 2;
		for(int i = 0; i < n; i++)
			cin >> tmp >> x[i] >> y[i];
		for (int i = 0; i < 1 << 16; i++)
			memo[i] = -10;
		double ans = dp(0);
		printf("Case %d: %.2f\n", t, ans);
	}
	return 0;
}
