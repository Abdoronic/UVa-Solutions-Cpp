#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< vector<int> > factors;

void sieveNumFactors(int N) {
	factors.assign(N + 1, vector<int>());
	for(int i = 2; i <= N; i++) {
		if(factors[i].empty()) {
			for(int j = i; j <= N; j += i) {
				if(j % i == 0 && i != j)
					factors[j].push_back(i);
			}
 		}
	}
}

int bfs(int s, int t) {
	vector<bool> vis(1001, false);
	queue<int> nodes, costs;
	nodes.push(s);
	costs.push(0);
	while(!nodes.empty()) {
		int u = nodes.front();
		int cost = costs.front();
		nodes.pop(); costs.pop();
		vis[u] = true;
		if(u == t) return cost;
		for(int v : factors[u]) {
			if(u + v <= t && !vis[u + v]) {
				nodes.push(u + v);
				costs.push(cost + 1);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int s, t;
	sieveNumFactors(1000);
	for(int tc = 1; cin >> s >> t; tc++) {
		if(s == 0) break;
		printf("Case %d: %d\n", tc, bfs(s, t));
	}
	return 0;
}
