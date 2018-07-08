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

int n, ans;

bool adj[101][101];
int parent[101];

bool sorted(int a, int b, int c) { return (a < b && b < c) || (a > b && b > c); }

void dfs(int u, int d) {
	if(d == 3) {
		if(adj[u][parent[parent[u]]] && sorted(u, parent[u], parent[parent[u]])) {
			printf("%d %d %d\n", parent[parent[u]] + 1, parent[u] + 1, u + 1);
			ans++;
		}
		return;
	}
	for(int j = 0; j < n; j++) {
		if(adj[u][j] && j != u) {
			parent[j] = u;
			dfs(j, d + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> n) {
		ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> adj[i][j];
		memset(parent, 0, sizeof parent);
		for(int i = 0; i < n; i++) {
			dfs(i, 1);
		}
		printf("total:%d\n\n", ans);
	}
	return 0;
}
