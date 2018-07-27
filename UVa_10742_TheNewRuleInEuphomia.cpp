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

vector<int> primes;
vector<bool> isPrime;

void sieve(int N) {
	isPrime.assign(N + 1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i <= N; i++) {
		if(isPrime[i]) {
			primes.push_back(i);
			if(1LL * i * i <= N)
				for(int j = i * i; j <= N; j += i)
					isPrime[j] = false;
 		}
	}
}

int bs(int t) {
	int lo = 0, hi = (int)primes.size() - 1, mid, ans = -1;
	while(lo <= hi) {
		mid = (hi - lo) / 2 + lo;
		if(primes[mid] <= t) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(1000000);
	int n;
	for(int tc = 1; cin >> n; tc++) {
		if(n == 0) break;
		if(n == 2 || n == 3) {
			printf("Case %d: 0\n", tc);
			continue;
		}
		int mid = floor(1.0 * n / 2);
		int idx = bs(mid);
		int cnt = (idx * (idx + 1)) / 2;
		int i = idx, j = idx + 1;
		while(i >= 0 && j < primes.size() && primes[j] <= n) {
			if(primes[j] + primes[i] <= n) {
				cnt += i + 1;
				j++;
			} else {
				i--;
			}
		}
		printf("Case %d: %d\n", tc, cnt);
	}
	return 0;
}
