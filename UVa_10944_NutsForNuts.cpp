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

int n, r, c, startX, startY, MOVES = 8;
vii nl;
int memo[20][20][1 << 15];

inline int dist(int x1, int y1, int x2, int y2) { return max(abs(x1 - x2), abs(y1 - y2)); }

int dp(int i, int j, int nuts) {
	if(nuts == (1 << n) - 1 )
		return dist(i, j, startX, startY);
	if(memo[i][j][nuts] != -1) return memo[i][j][nuts];
	int ans = INF;
	for(int k = 0; k < n; k++) {
		if((nuts & (1 << k)) == 0)
			ans = min(ans, dist(i, j, nl[k].first, nl[k].second)
					+ dp(nl[k].first, nl[k].second, nuts | (1 << k)));
	}
	return memo[i][j][nuts] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	while(cin >> r >> c) {
		nl.clear();
		for(int i = 0; i < r; i++) {
			cin >> line;
			for(int j = 0; j < c; j++) {
				if(line[j] == '#') {
					nl.pb({i, j});
				} else if(line[j] == 'L') {
					startX = i; startY = j;
				}
			}
		}
		n = nl.size();
		memset(memo, -1, sizeof memo);
		cout << dp(startX, startY, 0) << '\n';
	}
	return 0;
}
