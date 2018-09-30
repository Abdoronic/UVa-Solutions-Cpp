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

int arr[101][101];
bool vis[101][101];
int r, c, m, n;
vi dr, dc;

bool inBound(int i, int j) {
	return i >= 0 && i < r && j >= 0 && j < c;
}

void bfs() {
	queue<ii> line;
	line.push( { 0, 0 });
	vis[0][0] = true;
	while (!line.empty()) {
		ii v = line.front();
		line.pop();
		int x = v.first, y = v.second;
		for (int i = 0; i < dr.size(); i++) {
			int mx = x + dr[i], my = y + dc[i];
			if (inBound(mx, my) && arr[mx][my] != -1) {
				arr[x][y]++;
				if (!vis[mx][my]) {
					line.push( { mx, my });
					vis[mx][my] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, w, x, y;
	cin >> tc;
	for (int t = 1; tc--; t++) {
		cin >> r >> c >> m >> n;
		if (m == 0 || n == 0) {
			dr = { -m, m, -n, n };
			dc = { -n, n, -m, m};
		} else if(m == n) {
			dr = { -m, -m, m, m };
			dc = { -n, n, -n, n };
		} else {
			dr = { -m, -m, m, m, -n, n, -n, n };
			dc = { -n, n, -n, n, -m, -m, m, m };
		}
		cin >> w;
		memset(arr, 0, sizeof arr);
		memset(vis, false, sizeof vis);
		while (w--) {
			cin >> x >> y;
			arr[x][y] = -1;
		}
		bfs();
		int odd = 0, even = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] > 0 || (i == 0 && j == 0)) {
					if (arr[i][j] % 2 == 0)
						even++;
					else
						odd++;
				}
			}
		}
		printf("Case %d: %d %d\n", t, even, odd);
	}
	return 0;
}
