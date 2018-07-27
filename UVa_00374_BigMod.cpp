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

int MOD;

int fastPow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1)
			res = ((res % MOD) * (a % MOD)) % MOD;
		a = ((a % MOD) * (a % MOD)) % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int B, P;
	while(cin >> B >> P >> MOD)
		cout << fastPow(B, P) << '\n';
	return 0;
}
