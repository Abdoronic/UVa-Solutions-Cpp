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
vector<vi> adj;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n) {
		if (n == 0) break;
		adj.assign(n + 1, vi());
		vi color(n + 1, -1);
		int a, b;
		while (cin >> a >> b) {
			if (a == 0) break;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		bool isBipartite = true;
		queue<int> line;
		line.push(1);
		color[1] = 0;
		while (!line.empty() && isBipartite) {
			int u = line.front();
			line.pop();
			for (int v : adj[u]) {
				if (color[v] == -1) {
					color[v] = 1 ^ color[u];
					line.push(v);
				} else if (color[v] == color[u]) {
					isBipartite = false;
					break;
				}
			}
		}
		cout << (isBipartite ? "YES" : "NO") << '\n';
	}
	return 0;
}
