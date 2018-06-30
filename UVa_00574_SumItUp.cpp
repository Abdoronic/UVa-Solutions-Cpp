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

int n;
int arr[15];
set<string, greater<string> > sets;

void solve(int i, int sum, string numbers) {
	if(i == n || sum == 0) {
		if(sum == 0) {
			numbers[numbers.length()-1] = '\n';
			sets.insert(numbers);
		}
		return;
	}
	if(sum - arr[i] >= 0)
		solve(i+1, sum-arr[i], numbers + to_string(arr[i]) +"+");
	solve(i+1, sum, numbers);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	while(true) {
		cin >> t >> n;
		if(n == 0) break;
		sets = set<string, greater<string> >();
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		cout << "Sums of " << t << ":\n";
		solve(0, t, "");
		if(!sets.size())
			cout << "NONE\n";
		else
			for(string i : sets)
				cout << i;
	}
	return 0;
}
