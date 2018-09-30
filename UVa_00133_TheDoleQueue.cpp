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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, m;
	while(cin >> n >> k >> m) {
		if(n == 0) break;
		vi vis(n, false);
		int rem = n;
		int i = 0, j = n - 1;
		vii ans;
		while(rem) {
			int a = -1, b = -1;
			int stepA = k;
			while(stepA) {
				if(!vis[i])
					stepA--;
				if(stepA)
					i = (i + 1) % n;
			}
			int stepB = m;
			while(stepB && rem) {
				if(!vis[j])
					stepB--;
				if(stepB)
					j = ((j - 1) % n + n) % n;
			}
			vis[i] = true;
			vis[j] = true;
			a = i + 1;
			b = j + 1;
			rem -= 2;
			if(i == j) {
				b = -1;
				rem++;
			}
			ans.pb( { a, b });
		}
		for(i = 0; i < ans.size(); i++) {
			ii p = ans[i];
			printf("%3d", p.first);
			if(p.second != -1)
				printf("%3d", p.second);
			printf("%c", i == (int)ans.size() - 1 ? '\n' : ',');
		}
	}
	return 0;
}
