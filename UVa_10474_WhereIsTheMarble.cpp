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
	int N, Q, x;
	int arr[10005];
	for(int t = 1; true; t++) {
		cin >> N >> Q;
		if(N == 0) break;
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		sort(arr, arr+N);
		printf("CASE# %d:\n", t);
		while(Q--) {
			cin >> x;
			if(binary_search(arr, arr+N, x))
				printf("%d found at %d\n", x, lower_bound(arr, arr+N, x) - arr + 1);
			else
				printf("%d not found\n", x);
		}
	}
	return 0;
}
