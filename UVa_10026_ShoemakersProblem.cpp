#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back

#define INF int(1e9)
#define EPS 1e-9
#define MOD int(1e9 + 7)

bool compare(const iii& x, const iii& y) {
	return x.first.first*y.first.second < x.first.second*y.first.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC, N;
	iii arr[1005];
	cin >> TC;
	while (TC--) {
		cin >> N;
		int t, s;
		int cumTime[N];
		cumTime[0] = 0;
		for (int i = 0; i < N; i++) {
			cin >> t >> s;
			arr[i] = { {t, s}, i+1};
		}
		stable_sort(arr, arr+N, compare);
		for (int i = 0; i < N; i++)
			cout << arr[i].second << (i < N - 1 ? ' ' : '\n');
		if(TC > 0)
			cout << '\n';
	}
	return 0;
}
