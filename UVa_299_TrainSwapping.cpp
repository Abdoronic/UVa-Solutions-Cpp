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
	int t, n;
	int arr[55];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(arr[i] > arr[j])
					ans++;
		cout << "Optimal train swapping takes " << ans << " swaps.\n";
	}
	return 0;
}
