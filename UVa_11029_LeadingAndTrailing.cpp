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
#define MOD 1000

int multiplyMod(int a, int b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}

int fastPow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1)
			res = multiplyMod(res, a);
		a = multiplyMod(a, a);
		n >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, a, n;
	cin >> tc;
	while(tc--) {
		cin >> a >> n;
		int ttt = fastPow(a, n);
		double c = 1.0 * n * log(a) / log(10);
		c -= floor(c);
		c = pow(10, c);
		int lll = floor(c * 100);
		printf("%d...%03d\n", lll, ttt);
	}
	return 0;
}
