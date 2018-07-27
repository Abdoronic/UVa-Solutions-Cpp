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

vector<int> nod;
vector<int> sod;

void sieve(int N) {
	nod.assign(N + 1, 1);
	sod.assign(N + 1, 1);
	for(int i = 2; i <= N; i++) {
		if(nod[i] == 1) {
			for(int j = i; j <= N; j += i) {
				int x = j, pf = 1, e = 0;
				while(x % i == 0 && ++pf && ++e) x /= i;
				nod[j] *= pf;
				sod[j] *= ((pow(i, e + 1) - 1) / (i - 1));
			}
 		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(100000);
	int tc, a, b, k;
	cin >> tc;
	while(tc--) {
		cin >> a >> b >> k;
		ll delta = 0, sigma = 0;
		for(int i = a; i <= b; i++) {
			if(i % k == 0) {
				delta += nod[i];
				sigma += sod[i];
			}
		}
		cout << delta << ' ' << sigma << '\n';
	}
	return 0;
}
