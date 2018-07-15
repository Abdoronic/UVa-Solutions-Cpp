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

struct DSU {
	int n;
	int* p;
	int* rank;
	vi size;

	DSU (int n) {
		this->n = n;
		this->p = new int[n];
		this->rank = new int[n];
		size.assign(n, 1);
		for(int i = 0; i < n; i++) {
			p[i] = i;
			rank[i] = 0;
		}
	}

	int findSet(int i) { return i == p[i] ? i : p[i] = findSet(p[i]); }

	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

	void merge(int i, int j) {
		i = findSet(i);
		j = findSet(j);
		if(i == j) return;
		if(rank[i] < rank[j]) {
			p[i] = j;
			size[j] += size[i];
		} else {
			p[j] = i;
			if(rank[i] == rank[j])
				rank[i]++;
			size[i] += size[j];
		}
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, n, m, u, v;
	cin >> tc;
	while(tc--) {
		cin >> n >> m;
		DSU tree(n);
		while (m--) {
			cin >> u >> v;
			tree.merge(u - 1, v - 1);
		}
		cout << *max_element(all(tree.size)) << '\n';
	}
	return 0;
}
