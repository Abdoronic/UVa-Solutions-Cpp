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

vector<int> factors;

void sieve(int N) {
	factors.assign(N + 1, 0);
	for(int i = 2; i <= N; i++) {
		if(factors[i] == 0) {
			for(int j = i; j <= N; j += i) {
				int N = j;
				while(N % i == 0) {
					N /= i;
					factors[j]++;
				}
			}
 		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(10000001);
	for(int i = 1; i < factors.size(); i++)
		factors[i] += factors[i - 1];
	int n;
	for(int t = 1; cin >> n; t++) {
		if(n < 0) break;
		int fac = lower_bound(all(factors), n) - factors.begin();
		if(fac == factors.size() || factors[fac] != n)
			printf("Case %d: Not possible.\n", t);
		else
			printf("Case %d: %d!\n", t, fac);
	}
	return 0;
}
