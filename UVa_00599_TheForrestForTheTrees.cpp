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
bool vis[30];

int dfs(int u) {
	int ans = 0;
	for(int j = 0; j < adj[u].size(); j++) {
		int v = adj[u][j];
		if(!vis[v]) {
			vis[v] = true;
			ans += 1 + dfs(v);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC;
	string line;
	cin >> TC;
	getline(cin, line);
	while (TC--) {
		memset(vis, false, sizeof(vis));
		map<char, int> mapToIdx;
		vector< pair<char, char> > edge;
		while (getline(cin, line)) {
			if (line[0] == '*')
				break;
			edge.pb( { line[1], line[3] });
		}
		getline(cin, line);
		istringstream ss(line);
		int N = 0;
		for (int i = 0; getline(ss, line, ','); i++) {
			mapToIdx[line[0]] = i;
			N++;
		}
		adj.assign(N, vi());
		for (int i = 0; i < edge.size(); i++) {
			int u = mapToIdx[edge[i].first];
			int v = mapToIdx[edge[i].second];
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int trees = 0, acrons = 0, nodes;
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				nodes = dfs(i);
				if(nodes)
					trees++;
				else
					acrons++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acrons);
	}
	return 0;
}
