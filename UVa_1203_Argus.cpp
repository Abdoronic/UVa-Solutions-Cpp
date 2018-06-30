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
	int key, val, k;
	string s;
	priority_queue<ii, vii, greater<ii> > stream;
	map<int, int> periods;
	while(true) {
		cin >> s;
		if(s == "#")
			break;
		cin >> key >> val;
		stream.push({val, key});
		periods.insert({key, val});
	}
	cin >> k;
	while(k--) {
		ii curr = stream.top();
		stream.pop();
		cout << curr.second << '\n';
		curr.first += periods[curr.second];
		stream.push(curr);
	}
	return 0;
}
