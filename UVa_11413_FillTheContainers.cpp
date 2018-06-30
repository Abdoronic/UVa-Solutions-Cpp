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

int N, M;
int arr[1005];

inline bool p(int c) {
	int count = 1;
	int load = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i] > c) return false;
		if(load + arr[i] > c) {
			load = arr[i];
			count++;
		} else {
			load += arr[i];
		}
	}
	return count <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> N >> M) {
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		int lo = 1, hi = int(1e9+10), ans = -1, mid;
		while(lo <= hi) {
			mid = lo + (hi - lo)/2;
			if(p(mid)) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
