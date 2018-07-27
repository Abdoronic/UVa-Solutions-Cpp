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

void sieve(int N) {  //all prime numbers from 1 to N aprox. (N / log N) numbers
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
		if(p * p > N) break;
		if(N % p == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(1000000);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		for(int p : primes) {
			if(p == 2) continue;
			if(p > n) break;
			if(checkPrime(n - p)) {
				printf("%d = %d + %d\n", n, p, n - p);
				break;
			}
		}
	}
	return 0;
}
