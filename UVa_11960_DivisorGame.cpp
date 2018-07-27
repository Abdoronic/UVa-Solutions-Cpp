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

vector<int> divisors;

void sieveNumDivsors(int N) {
	divisors.assign(N + 1, 1);
	for(int i = 2; i <= N; i++) {
		if(divisors[i] == 1) {
			for(int j = i; j <= N; j += i) {
				int N = j, pf = 1;
				while(N % i == 0 && ++pf) N /= i;
				divisors[j] *= pf;
			}
 		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieveNumDivsors(1000000);
	int maxVal = 0, maxNum = 0;
	for(int i = 0; i < divisors.size(); i++) {
		if(divisors[i] >= maxVal) {
			maxVal = divisors[i];
			maxNum = i;
		}
		divisors[i] = maxNum;
	}
	int tc, n;
	cin >> tc;
	while(tc--) {
		cin >> n;
		printf("%d\n", divisors[n]);
	}
	return 0;
}
