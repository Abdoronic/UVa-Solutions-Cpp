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

int primeFactors(int N) {
	int factors = 0;;
	for(int p : primes) {
		if(p * p > N) break;
		while(N % p == 0) {
			N /= p;
			factors++;
		}
	}
	if(N > 1)
		factors++;
	return factors;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(1000001);
	int cum[1000001];
	memset(cum, 0, sizeof cum);
	int n = 1;
	for(int i = 2; i < 1000001; i++)
		cum[i] = cum[i - 1] + primeFactors(i);
	while(cin >> n)
		printf("%d\n", cum[n]);
	return 0;
}
