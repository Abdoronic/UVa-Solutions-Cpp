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
bool vis[101];
vector<vector<int> > adj;
vector<int> ts;

void dfs(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
	ts.push_back(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, u, v;
	while (cin >> n >> m) {
		if(n == 0) break;
		adj.assign(n + 1, vector<int>());
		memset(vis, false, sizeof vis);
		ts.clear();
		while (m--) {
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		for (int i = (int) ts.size() - 1; i >= 0; i--)
			printf("%d%c", ts[i], i == 0 ? '\n' : ' ');
	}
	return 0;
}
