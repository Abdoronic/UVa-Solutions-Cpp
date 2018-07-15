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

	DSU (int n) {
		this->n = n;
		this->p = new int[n];
		this->rank = new int[n];
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
		} else {
			p[j] = i;
			if(rank[i] == rank[j])
				rank[i]++;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, s, p;
	while(true) {
		cin >> n >> m;
		if(n == 0) break;
		DSU rmq(n);
		while(m--) {
			cin >> k >> s;
			while(k-- > 1) {
				cin >> p;
				rmq.merge(s, p);
			}
		}
		int cnt = 1;
		for(int i = 1; i < n; i++)
			if(rmq.isSameSet(0, i))
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
