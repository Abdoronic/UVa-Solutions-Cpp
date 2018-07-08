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
int startX, startY, endX, endY;
bool closed[35][35][35][35];
ll memo[35][35];

ll dp(int x, int y) {
	if(x == n || y == n || x < 0 || y < 0) return 0;
	if(x == endX && y == endY) return 1;
	if(memo[x][y] != -1) return memo[x][y];
	ll ans = 0;
	if(!closed[x][y][x + 1][y])
		ans += dp(x + 1, y);
	if(!closed[x][y][x][y + 1])
		ans += dp(x, y + 1);
	return memo[x][y] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, w, x, y;
	char d;
	cin >> tc;
	while(tc--) {
		cin >> n;
		cin >> startX >> startY >> endX >> endY;
		startX--; startY--; endX--; endY--;
		memset(closed, false, sizeof closed);
		cin >> w;
		while(w--) {
			cin >> x >> y >> d;
			x--; y--;
			if(d == 'N') {
				closed[x][y][x][y + 1] = true;
			} else if(d == 'S' && y > 0) {
				closed[x][y - 1][x][y] = true;
			} else if(d == 'E') {
				closed[x][y][x + 1][y] = true;
			} else if(d == 'W' && x > 0) {
				closed[x - 1][y][x][y] = true;
			}
		}
		memset(memo, -1, sizeof memo);
		cout << dp(startX, startY) << '\n';
	}
	return 0;
}
