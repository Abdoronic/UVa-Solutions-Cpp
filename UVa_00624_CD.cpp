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

int n, length;
int arr[25];
priority_queue< pair<int, string> > answers;

void solve(int i, int time, string tracks) {
	if(i == n) {
		if(time != 0)
			answers.push({time, tracks});
		return;
	}
	if(time + arr[i] <= length)
		solve(i+1, time + arr[i], tracks + to_string(arr[i]) + " ");
	solve(i+1, time, tracks);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> length >> n) {
		answers = priority_queue< pair<int, string> >();
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		solve(0, 0, "");
		pair<int, string> ans = answers.top();
		cout << ans.second << "sum:" << ans.first << '\n';
	}
	return 0;
}
