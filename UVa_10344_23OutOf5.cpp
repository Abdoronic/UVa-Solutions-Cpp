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

int n = 5;
int arr[5];

int solve(int i, int sum) {
	if (i == n) {
		if (sum == 23)
			return 1;
		return 0;
	}
	int ans = 0;
	ans += solve(i+1, sum * arr[i]);
	ans += solve(i+1, sum + arr[i]);
	ans += solve(i+1, sum - arr[i]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum == 0)
			break;
		sort(arr, arr+n);
		int ans = 0;
		bool flag = false;
		do {
			ans += solve(1, arr[0]);
			if(ans > 0) {
				flag = true;
				break;
			}
		} while(next_permutation(arr, arr + n));
		cout << (flag ? "Possible" : "Impossible") << '\n';
	}
	return 0;
}
