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

vector<ii> primeFactorsPowers(int N) {
	vector<ii> factors;
	for(int p : primes) {
		if(p * p > N)
			break;
		int e = 0;
		while(N % p == 0 && ++e) N /= p;
		if(e > 0)
			factors.push_back({p, e});
	}
	if(N > 1)
		factors.push_back({N, 1});
	return factors;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	sieve(100000);
	while(true) {
		getline(cin, line);
		istringstream ss(line);
		int p, e;
		ss >> p;
		if(p == 0) break;
		ss >> e;
		int num = pow(p, e);
		while(ss >> p >> e)
			num *= pow(p, e);
		num--;
		vii factors = primeFactorsPowers(num);
		for(int i = (int)factors.size() - 1; i >= 0; i--)
			printf("%d %d%c", factors[i].first, factors[i].second, i == 0 ? '\n' : ' ');
	}
	return 0;
}
