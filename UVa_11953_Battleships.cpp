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

vector< vector<char> > water;
vector< vector<bool> > vis;
int d[] = {-1, 1};

inline bool inBounds(int x, int y) {
	return x >= 0 && y >= 0 && x < water.size() && y < water.size();
}

int dfsHorz(int x, int y) {
	vis[x][y] = true;
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		int nx = x + d[i];
		if(inBounds(nx, y) && !vis[nx][y] && water[nx][y] != '.')
			ans += 1 + dfsHorz(nx, y);
	}
	return ans;
}

int dfsVert(int x, int y) {
	vis[x][y] = true;
	int ans = 0;
	for(int i = 0; i < 2; i++) {
		int ny = y + d[i];
		if(inBounds(x, ny) && !vis[x][ny] && water[x][ny] != '.')
			ans += 1 + dfsVert(x, ny);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, n;
	cin >> tc;
	for(int t = 1; tc--; t++) {
		cin >> n;
		water.assign(n, vector<char>(n));
		vis.assign(n, vector<bool>(n, false));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> water[i][j];
		int cc = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!vis[i][j] && water[i][j] == 'x') {
					int cnt = dfsHorz(i, j);
					cc++;
					if(cnt == 0) {
						vis[i][j] = false;
						cnt = dfsVert(i, j);
					}
				}
			}
		}
		printf("Case %d: %d\n", t, cc);
	}
	return 0;
}
