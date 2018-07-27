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

vector< pair<int, int> > primeFactorsPowers(int N) {
	vector<	pair<int, int> > factorsPowers;
	for(int p : primes) {
		if(p * p > N)
			break;
		int e = 0;
		while(N % p == 0 && ++e) N /= p;
		if(e > 0)
			factorsPowers.push_back({p, e});
	}
	if(N > 1)
		factorsPowers.push_back({N, 1});
	return factorsPowers;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(100000);
	int fac, div;
	while(cin >> fac >> div) {
		vii factors = primeFactorsPowers(div);
		bool can = true;
		for(auto i : factors) {
			if(!can) break;
			int p = i.first;
			int e = i.second;
			int sum = fac / p;
			ll number = p;
			while(sum < e) {
				number *= p;
				if(1ll * fac / number == 0)
					break;
				sum += fac / number;
			}
			if(sum < e)
				can = false;
		}
		if(can)
			printf("%d divides %d!\n", div, fac);
		else
			printf("%d does not divide %d!\n", div, fac);
	}
	return 0;
}
