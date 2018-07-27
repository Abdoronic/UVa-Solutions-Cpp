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
#define MOD int(1e9)

ll N, M, twos, fives;

void remove(ll& a) {
	while(a > 1) {
		if(a % 2 == 0) {
			a /= 2;
			twos++;
		} else if(a % 5 == 0) {
			a /= 5;
			fives++;
		} else {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> N >> M) {
		twos = 0; fives = 0;
		ll pre = 1, curr = 1;
		for(ll i = N - M + 1; i <= N; i++) {
			ll x = i;
			remove(x);
			curr = ((x % MOD) * (pre % MOD)) % MOD;
			remove(curr);
			pre = curr;
		}
		if(twos < fives) {
			fives -= twos;
			while(fives--)
				curr = ((curr % MOD) * (5 % MOD)) % MOD;
		} else {
			twos -= fives;
			while(twos--)
				curr = ((curr % MOD) * (2 % MOD)) % MOD;
		}
		cout << curr % 10 << '\n';
	}
	return 0;
}
