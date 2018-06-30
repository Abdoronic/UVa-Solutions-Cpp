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

int arr[105];
char typ[105];
int TC, N, L;

int getMaxLeap(int l, int r) {
	int p = 0;
	vi left, right;
	left.pb(arr[l]); right.pb(arr[l]);
	for(int i = l + 1; i < r; i++) {
		if(p) {
			right.pb(arr[i]);
		} else {
			left.pb(arr[i]);
		}
		p = 1 - p;
	}
	left.pb(arr[r]); right.pb(arr[r]);
	int maxLeap = 0;
	for(int i = 1; i < left.size(); i++)
		maxLeap = max(maxLeap, left[i] - left[i-1]);
	for(int i = 1; i < right.size(); i++)
		maxLeap = max(maxLeap, right[i] - right[i-1]);
	return maxLeap;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> TC;
	for (int t = 1; TC--; t++) {
		cin >> N >> L;
		string line;
		for (int i = 1; i <= N; i++) {
			cin >> line;
			typ[i] = line[0];
			arr[i] = stoi(line.substr(2, line.length()-2));
		}
		arr[0] = 0;
		arr[N + 1] = L;
		typ[N + 1] = 'B';
		int ans = 0;
		int last = 0;
		for (int i = 1; i < N + 2; i++)
			if (typ[i] == 'B') {
				ans = max(ans, getMaxLeap(last, i));
				last = i;
			}
		printf("Case %d: %d\n", t, ans);

	}
	return 0;
}
