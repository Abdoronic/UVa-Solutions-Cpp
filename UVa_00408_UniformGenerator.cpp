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
	int step, mod;
	while(cin >> step >> mod) {
		int preStep = 0, currStep;
		vector<bool> vis(mod, false);
		vis[0] = true;
		while(true) {
			currStep = (preStep + step) % mod;
			if(vis[currStep])
				break;
			vis[currStep] = true;
			preStep = currStep;
		}
		bool good = true;
		for(bool b : vis)
			good &= b;
		printf("%10d%10d    %s\n\n", step, mod, good ? "Good Choice" : "Bad Choice");
	}
	return 0;
}
