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

vector<int> primeFactors(int N) {
	vector<int> factors;
	for(int p : primes) {
		if(p * p > N) break;
		while(N % p == 0) {
			N /= p;
			factors.push_back(p);
		}
	}
	if(N > 1)
		factors.push_back(N);
	return factors;
}
set<int> ans;
vi factors;
int c, r, e;

void backtrack(int idx, int g) {
	if(idx == factors.size() || e / g <= r) {
		if(e / g > r)
			ans.insert(e / g);
		return;
	}
	if(e / g > r) {
		ans.insert(e / g);
		backtrack(idx + 1, g * factors[idx]);
	}
	backtrack(idx + 1, g);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(100000);
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++) {
		cin >> c >> r;
		e = c - r;
		printf("Case #%d:", t);
		if(e == 0) {
			printf(" 0\n");
			continue;
		}
		ans.clear();
		factors = primeFactors(e);
		backtrack(0, 1);
		for(int i : ans)
			printf(" %d", i);
		printf("\n");
	}
	return 0;
}
