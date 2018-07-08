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

int n;
int arr[2001];
int lis[2001], lds[2001];

int LIS(int start, int end, bool inc) {
	vi v;
	for(int i = start; i < end; i++) {
		int val = arr[i];
		if(inc) {
			if(val <= arr[start] && i != start)
				continue;
		} else {
			if(val >= arr[end - 1] && i != end - 1)
				continue;
		}
		int idx = upper_bound(all(v), val) - v.begin();
		if(idx == v.size())
			v.pb(val);
		else
			v[idx] = val;
	}
	return v.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		for(int i = 0; i < n; i++)
			lis[i] = LIS(i, n, true);
		reverse(arr, arr + n);
		for(int i = 0; i < n; i++)
			lds[i] = LIS(0, n - i, false);
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, lis[i] + lds[i] - 1);
		cout << ans << '\n';
	}
	return 0;
}
