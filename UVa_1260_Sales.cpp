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
	int arr[1005];
	cin >> t;
	while (t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		int sum = 0;
		for(int i = 1; i < n; i++)
			for(int j = 0; j < i; j++)
				if(arr[j] <= arr[i])
					sum++;
		cout << sum << '\n';
	}
	return 0;
}
