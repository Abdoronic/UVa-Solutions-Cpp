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

void sieve(int N) {  //all prime numbers from 1 to N;
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

bool checkPrime(int N) {
	if(N < isPrime.size())
		return isPrime[N];
	for(int p : primes) {
		if(p * p > N)
			break;
		if(N % p == 0)
			return false;
	}
	return true;
}

int decompose(int x) {
	if(!checkPrime(x)) return 0;
	int sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return checkPrime(sum) ? 1 : 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(1000000);
	int cum[1000000];
	memset(cum, 0, sizeof cum);
	for(int i = 1; i < 1000000; i++)
		cum[i] += decompose(i) + cum[i - 1];
	int t, l, r;
	cin >> t;
	while(t--) {
		cin >> l >> r;
		printf("%d\n", cum[r] - cum[l - 1]);
	}
	return 0;
}
