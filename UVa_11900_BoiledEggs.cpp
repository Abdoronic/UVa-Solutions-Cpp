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
	int tc , n, p, q;
	int arr[35];
	cin >> tc;
	for(int t = 1; tc--; t++) {
		cin >> n >> p >> q;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		int count = 0;
		int sum = 0;
		for(int i = 0 ; i < n; i++) {
			if(count+1 <= p && sum + arr[i] <= q) {
				sum += arr[i];
				count++;
			}
		}
		cout << "Case " << t <<": " << count << '\n';
	}
	return 0;
}
