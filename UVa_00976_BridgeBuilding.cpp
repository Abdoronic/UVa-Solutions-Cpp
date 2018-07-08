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

int r, n, B, S;
string mapa[1001];
int arr[1001];
int memo[1001][101];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

inline bool inBound(int i, int j) { return i >= 0 && j >= 0 && i < r && j < n; }

void floodFill(int startX, int startY, char c) {
	queue<ii> bfs;
	bfs.push({startX, startY});
	mapa[startX][startY] = c;
	while(!bfs.empty()) {
		ii u = bfs.front();
		bfs.pop();
		int i = u.first, j = u.second;
		for(int k = 0; k < 4; k++) {
			int x = i + dr[k], y = j + dc[k];
			if(inBound(x, y) && mapa[x][y] == '#') {
				mapa[x][y] = c;
				bfs.push({x, y});
			}
		}
	}
}

int dp(int i, int b) {
	if(b == B) return 0;
	if(i >= n) return INF;
	if(memo[i][b] != -1) return memo[i][b];
	int ans = INF;
	ans = min(ans, arr[i] + dp(i + S + 1, b + 1));
	ans = min(ans, dp(i + 1, b));
	return memo[i][b] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> r >> n >> B >> S) {
		for(int i = 0; i < r; i++)
			cin >> mapa[i];
		floodFill(0, 0, 'N');
		floodFill(r - 1, 0, 'S');
		for(int j = 0; j < n; j++) {
			int last;
			for(int i = 0; i < r; i++) {
				if(mapa[i][j] == 'N') {
					last = i;
				} else if(mapa[i][j] == 'S') {
					arr[j] = i - last - 1;
					break;
				}
			}
		}
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0) << '\n';
	}
	return 0;
}
