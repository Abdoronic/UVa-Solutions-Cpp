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

int N, S;
int arr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> N >> S) {
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		int i = 0, j = 0, ans = INF;
		int sum = arr[0];
		while(i < N && j < N) {
			if(i > j) {
				j = i;
				sum += arr[i];
			}
			if(sum >= S) {
				ans = min(ans, j - i + 1);
				sum -= arr[i++];
			} else {
				sum += arr[++j];
			}
		}
		if(ans == INF) ans = 0;
		cout << ans << '\n';
	}
	return 0;
}
