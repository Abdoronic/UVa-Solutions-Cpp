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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(1000000);
	int t, l, r;
	cin >> t;
	while(t--) {
		cin >> l >> r;
		int i = lower_bound(all(primes), l) - primes.begin();
		if(i == primes.size() || primes[i] >= r) {
			printf("No jumping champion\n");
			continue;
		}
		int j = lower_bound(all(primes), r) - primes.begin();
		if(j == primes.size() || primes[j] > r) j--;
		if(j - i < 1) {
			printf("No jumping champion\n");
			continue;
		}
		map<int, int> diff;
		for(int k = i; k <= j - 1; k++)
			diff[primes[k + 1] - primes[k]]++;
		int maxVal = 0, d = 0;
		bool rep = false;
		for(ii k : diff) {
			if(k.second == maxVal) {
				rep = true;
			} else if(k.second > maxVal) {
				rep = false;
				maxVal = k.second;
				d = k.first;
			}
		}
		if(rep)
			printf("No jumping champion\n");
		else
			printf("The jumping champion is %d\n", d);
	}
	return 0;
}
