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

int n, b1, b2;
int x[101], y[101];
double memo[2][2][101][101][101];
vi pathI, pathJ;

double dist(int i, int j) {
	return hypot(x[i] - x[j], y[i] - y[j]);
}

double dp(bool visI, bool visJ, int idx, int i, int j) {
	if(idx == n - 1) {
		if(visI && visJ)
			return dist(idx, i) + dist(idx, j);
		return INF;
	}
	if(memo[visI][visJ][idx][i][j] > -5) return memo[visI][visJ][idx][i][j];
	double ans = INF;
	ans = min(ans, dist(idx, i) + dp(idx == b1 || idx == b2 ? true : visI, visJ, idx + 1, idx, j));
	ans = min(ans, dist(idx, j) + dp(visI, idx == b1 || idx == b2 ? true : visJ, idx + 1, i, idx));
	return memo[visI][visJ][idx][i][j] = ans;
}

void trace(bool visI, bool visJ, int idx, int i, int j) {
	if(idx == n - 1) return;
	double ans = dp(visI, visJ, idx, i, j);
	double takeI = dist(idx, i) + dp(idx == b1 || idx == b2 ? true : visI, visJ, idx + 1, idx, j);
	if(abs(ans - takeI) < EPS) {
		pathI.pb(idx);
		trace(idx == b1 || idx == b2 ? true : visI, visJ, idx + 1, idx, j);
	} else {
		pathJ.pb(idx);
		trace(visI, idx == b1 || idx == b2 ? true : visJ, idx + 1, i, idx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int t = 1; true; t++) {
		cin >> n >> b1 >> b2;
		if(n == 0) break;
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 101; k++)
					for(int l = 0; l < 101; l++)
						for(int m = 0; m < 101; m++)
							memo[i][j][k][l][m] = -10;
		double ans = dp(0, 0, 1, 0, 0);
		printf("Case %d: %.2f\n", t, ans);
		pathI.clear(); pathJ.clear();
		trace(0, 0, 1, 0, 0);
		printf("0 ");
		for(int v : pathI)
			printf("%d ", v);
		printf("%d ", n - 1);
		reverse(all(pathJ));
		for(int v : pathJ)
			printf("%d ", v);
		printf("0\n");
	}
	return 0;
}
