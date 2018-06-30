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
	int n;
	int arr[5];
	while(true) {
		cin >> n;
		if(n == 0) break;
		map<string, int> tree;
		int t = n;
		while(t--) {
			for(int i = 0; i < 5; i++)
				cin >> arr[i];
			sort(arr, arr + 5);
			string s;
			for(int i : arr)
				s += to_string(i);
			if(tree.find(s) != tree.end())
				tree[s]++;
			else
				tree.insert({s, 1});
		}
		int ans = 0, maxi = 0;
		for(auto i : tree)
			maxi = max(maxi, i.second);
		for(auto i : tree)
			if(i.second == maxi)
				ans += maxi;
		cout << ans << '\n';
	}
	return 0;
}
