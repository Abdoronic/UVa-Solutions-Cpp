#include "bits/stdc++.h"

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

int n, taken;
int arr[16];
bool isPrime[32];

void seive() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i < 32; i++) {
		if(!isPrime[i])
			continue;
		for(int j = 2*i; j < 32; j += i)
			isPrime[j] = false;
	}
}

void solve(int idx) {
	if(idx == n) {
		for(int i = 0; i < n; i++)
			cout << arr[i] << (i == n-1? '\n' : ' ');
		return;
	}
	for(int i = 2; i <= n; i++) {
		int preSum = i + arr[idx-1];
		if(idx < n-1) {
			if(preSum < 32 && isPrime[preSum] && !(taken & (1<<i))) {
				taken |= (1<<i);
				arr[idx] = i;
				solve(idx+1);
				taken &= ~(1<<i);
			}
		} else {
			if(preSum < 32 && isPrime[preSum] && !(taken & (1<<i)) && isPrime[i+1]) {
				taken |= (1<<i);
				arr[idx] = i;
				solve(idx+1);
				taken &= ~(1<<i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	seive();
	for(int i = 1; cin >> n; i++) {
		if(i > 1)
			cout << '\n';
		taken = 0;
		arr[0] = 1;
		cout << "Case " << i << ":\n";
		solve(1);
	}
	return 0;
}
