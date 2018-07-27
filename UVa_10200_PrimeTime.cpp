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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(10000000);
	int prm[10001];
	memset(prm, 0, sizeof prm);
	for(int i = 0; i <= 10000; i++) {
		int e = i * i + i + 41;
		prm[i] += checkPrime(e);
		prm[i] += i > 0 ? prm[i - 1] : 0;
	}
	int l, r;
	while(cin >> l >> r) {
		double p = prm[r] - (l > 0 ? prm[l - 1] : 0);
		p = p * 100.0 / (r - l + 1);
		p *= 100;
		printf("%.2f\n", round(p) / 100);
	}
	return 0;
}
