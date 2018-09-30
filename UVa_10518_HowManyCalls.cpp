#include <bits/stdc++.h>
using namespace std;

int MOD;

vector< vector<int> > matrixMultiplyMod(vector< vector<int> > a,
		vector< vector<int> > b, int p, int q, int r) {
	vector< vector<int> > ans(p, vector<int>(r));
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < q; k++) {
				ans[i][j] += (1ll * a[i][k] * b[k][j]) % MOD;
				ans[i][j] %= MOD;
			}
	return ans;
}

vector< vector<int> > matrixPower(vector< vector<int> > a, long long p) {
	int n = a.size();
	vector< vector<int> > ans(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		ans[i][i] = 1;
	while (p) {
		if (p & 1)
			ans = matrixMultiplyMod(ans, a, n, n, n);
		a = matrixMultiplyMod(a, a, n, n, n);
		p >>= 1;
	}
	return ans;
}

int main() {
	long long n;
	vector< vector<int> > recurrence = { { 1, 1 }, { 1, 0 } };
	for (int t = 1;scanf("%lld%d", &n, &MOD); t++) {
		if (n + MOD == 0) break;
		auto ans = matrixPower(recurrence, n);
		int sol = ans[1][0] + ans[1][1];
		sol = 2 * sol - 1;
		printf("Case %d: %lld %d %d\n", t, n, MOD, sol % MOD);
	}
	return 0;
}
