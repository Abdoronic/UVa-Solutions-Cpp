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

bool compare(const ii& x, const ii& y) {
	if(x.first == y.first) {
		return x.second > y.second;
	} else {
		return x.first < y.first;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int L, G;
	int x, r;
	ii arr[10005];
	bool vis[10005];
	for(int t = 1; true; t++) {
		cin >> L >> G;
		if(L == 0) break;
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < G; i++) {
			cin >> x >> r;
			arr[i] = {max(x-r, 0), x+r};
		}
		sort(arr, arr+G, compare);
		int closed = 0;
		bool valid = true;
		if (arr[0].first > 0)
			valid = false;
		for(int i = 0; i < G && valid; i++) {
			ii p = arr[i];
			vis[i] = true;
			int j = i+1;
			if(p.second >= L) {
				while(j < G)
					if(!vis[j++])
						closed++;
				break;
			}
			int mx = p.second, count = 0;
			while(j < G && arr[j].first <= p.second) {
				if(arr[j].second > mx) {
					mx = arr[j].second;
					i = j - 1;
				}
				if(!vis[j])
					count++;
				vis[j++] = true;
			}
			if(count == 0 && p.second < L)
				valid = false;
			if(count > 0)
				closed += count - 1;
		}
		cout << (valid? closed : -1) << '\n';
	}
	return 0;
}
