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

int phi(int n) {
	int res = n;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) n /= i;
			res -= res / i;
		}
	}
	if(n > 1)
		res -= res / n;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int LIMIT = 50001;
	int arr[LIMIT];
	arr[1] = 1;
	for(int i = 2; i < LIMIT; i++)
		arr[i] = 2 * phi(i) + arr[i - 1];
	int n;
	while(cin >> n) {
		if(n == 0) break;
		cout << arr[n] << '\n';
	}
	return 0;
}
