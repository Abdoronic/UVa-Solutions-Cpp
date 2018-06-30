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
	while (cin >> n) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> p;
		int op, val;
		bool isS = true, isQ = true, isP = true;
		while (n--) {
			cin >> op >> val;
			if(isS + isQ + isP == 0) continue;
			if (op == 1) {
				s.push(val);
				q.push(val);
				p.push(val);
			} else {
				if(s.empty() || q.empty() || p.empty()) {
					isS = false; isQ = false; isP = false;
					continue;
				}
				int fromS = s.top();
				int fromQ = q.front();
				int fromP = p.top();
				s.pop();
				q.pop();
				p.pop();
				if (val != fromS)
					isS = false;
				if (val != fromQ)
					isQ = false;
				if (val != fromP)
					isP = false;
			}
		}
		if (isS + isQ + isP >= 2) {
			cout << "not sure" << '\n';
		} else {
			if (isS)
				cout << "stack" << '\n';
			if (isQ)
				cout << "queue" << '\n';
			if (isP)
				cout << "priority queue" << '\n';
			if (isS + isQ + isP == 0)
				cout << "impossible" << '\n';
		}
	}
	return 0;
}
