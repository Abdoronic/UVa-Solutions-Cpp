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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

inline ll lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		vi v;
		for(int i = 1; 1ll * i * i <= n; i++) {
			if(n % i == 0) {
				v.pb(i);
				if(n / i != i)
					v.pb(n / i);
			}
		}
		int cnt = 0;
		for(int i = 0; i < v.size(); i++)
			for(int j = i; j < v.size(); j++)
				if(lcm(v[i], v[j]) == n)
					cnt++;
		printf("%d %d\n", n, cnt);
	}
	return 0;
}
