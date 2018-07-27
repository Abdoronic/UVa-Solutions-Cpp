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

int multiplyMod(int a, int b) {
	return (1LL * (a % MOD) * (b % MOD)) % MOD;
}

int modPow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1)
			res = multiplyMod(res, a);
		a = multiplyMod(a, a);
		n >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(100000);
	while(cin >> MOD) {
		if(MOD == 0) break;
		if(!isPrime[MOD]) {
			bool fermat = true;
			for(int i = 2; i < MOD && fermat; i++) {
				if(modPow(i, MOD) != i)
					fermat = false;
			}
			if(fermat)
				printf("The number %d is a Carmichael number.\n", MOD);
			else
				printf("%d is normal.\n", MOD);
		} else {
			printf("%d is normal.\n", MOD);
		}
	}
	return 0;
}
