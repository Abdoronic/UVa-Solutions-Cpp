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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC, N;
	cin >> TC;
	while (TC--) {
		cin >> N;
		int count[N];
		memset(count, 0, sizeof(count));
		int mini = INF, x;
		string line;
		getline(cin, line);
		for(int i = 0; i < N; i++) {
			getline(cin, line);
			istringstream ss(line);
			while(ss >> x)
				count[i]++;
			mini = min(mini, count[i]);
		}
		bool first = true;
		for(int i = 0; i < N; i++) {
			if(count[i] == mini) {
				if(first) {
					cout << i+1;
					first = false;
				}
				else {
					cout << " " << i+1;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
