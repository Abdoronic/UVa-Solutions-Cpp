#include <bits/stdc++.h>

using namespace std;

int n;
int s[15];
vector<int> taken;

void backtrack(int idx) {
	if(idx == n) {
		if(taken.size() != 6) return;
		for(int i = 0; i < taken.size(); i++)
			printf("%d%c", taken[i], i == (int)taken.size() - 1 ? '\n' : ' ');
	} else {
		taken.push_back(s[idx]);
		backtrack(idx + 1);
		taken.pop_back();
		backtrack(idx + 1);
	}
}

int main() {
	for(int tc = 1; cin >> n; tc++) {
		if(n == 0) break;
		if(tc > 1) printf("\n");
		for(int i = 0; i < n; i++)
			cin >> s[i];
		backtrack(0);
	}
	return 0;
}
