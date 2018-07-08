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
int x[1001], y[1001], p[1001];
double memo[101][101][1001];

inline double dist(int x1, int y1, int x2, int y2) {
	return hypot(x1 - x2, y1 - y2);
}

double dp(int i, int j, int idx) {
	if(idx == n)
		return 1 + dist(i, j, 100, 100);
	if(memo[i][j][idx] > -5) return memo[i][j][idx];
	double ans = INF;
	ans = min(ans, 1 + dist(i, j, x[idx], y[idx]) + dp(x[idx], y[idx], idx + 1));
	ans = min(ans, p[idx] + dp(i, j, idx + 1));
	return memo[i][j][idx] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true) {
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> p[i];
		for(int i = 0; i < 101; i++)
			for(int j = 0; j < 101; j++)
				for(int k = 0; k < 1001; k++)
					memo[i][j][k] = -10;
		double ans = dp(0, 0, 0);
		printf("%.3f\n", ans);
	}
	return 0;
}
