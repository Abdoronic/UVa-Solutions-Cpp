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

vector<vi> adj;
vi path;
int emails[50005];
int depth[50005];
bool vis[50005];
bool currVis[50005];
bool wasCycle[50005];

int dfs(int u, int depth) {
	if(currVis[u]) {
		bool inCycle = false;
		for(int v : path) {
			if(v == u) inCycle = true;
			if(inCycle) wasCycle[v] = true;
		}
		return depth - emails[u] - 1;
	}
	if(vis[u]) return emails[u];
	int ans = 1;
	vis[u] = currVis[u] = true;
	path.pb(u);
	emails[u] = depth;
	for(int v : adj[u]) {
		ans += dfs(v, depth+1);
		if(wasCycle[v])
			ans--;
		currVis[v] = wasCycle[v] = false;
	}
	return emails[u] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, n;
	cin >> tc;
	for(int t = 1; tc--; t++) {
		cin >> n;
		adj.assign(n, vi());
		memset(emails, 0, sizeof emails);
		memset(vis, false, sizeof vis);
		memset(currVis, false, sizeof currVis);
		memset(wasCycle, false, sizeof wasCycle);
		int u, v;
		for(int i = 0; i < n; i++) {
			cin >> u >> v;
			adj[u-1].pb(v-1);
		}
		int max = -1 ,ans = -1;
		for(int i = 0; i < n; i++) {
			if (!vis[i]) {
				path = vi();
				dfs(i, 1);
				currVis[i] = wasCycle[i] = false;
			}
		}
		for(int i = 0; i < n; i++) {
			if(emails[i] > max) {
				max = emails[i];
				ans = i+1;
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
