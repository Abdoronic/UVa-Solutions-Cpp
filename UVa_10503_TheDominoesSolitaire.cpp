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

int n, m, taken, startX, startY, endX, endY;
int x[15];
int y[15];

int solve(int idx, int pre) {
	if(idx == n) {
		if(pre == endX)
			return 1;
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < m; i++) {
		if(!(taken & (1 << i))) {
			if(x[i] == pre) {
				taken |= (1 << i);
				ans += solve(idx+1, y[i]);
				taken &= ~(1 << i);
			} else if(y[i] == pre) {
				taken |= (1 << i);
				ans += solve(idx+1, x[i]);
				taken &= ~(1 << i);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true) {
		cin >> n;
		if(n == 0) break;
		cin >> m;
		cin >> startX >> startY >> endX >> endY;
		for(int i = 0; i < m; i++)
			cin >> x[i] >> y[i];
		taken = 0;
		int ans = solve(0, startY);
		cout << (ans? "YES" : "NO") << '\n';
	}
	return 0;
}
