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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int primeExponentsGCD(ll N, bool neg) {
	vector<int> powers;
	for(int p : primes) {
		if(1ll * p * p > N)
			break;
		int e = 0;
		while(N % p == 0 && ++e) N /= p;
		if(e > 0)
			powers.push_back(e);
	}
	if(N > 1)
		powers.push_back(1);
	int max = powers[0];
	for(int i = 1; i < powers.size(); i++)
		max = gcd(powers[i], max);
	while(neg && max % 2 == 0)
		max /= 2;
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(100000);
	ll n;
	while(cin >> n) {
		if(n == 0) break;
		printf("%d\n", primeExponentsGCD(abs(n), n < 0));
	}
	return 0;
}
