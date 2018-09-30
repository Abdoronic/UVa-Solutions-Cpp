#include <bits/stdc++.h>
using namespace std;

int m;
pair<int, int> inp[20005];
int arr[20005];
vector<int> v;

int bs(int target) {
	int lo = 0, hi = (int)v.size() - 1, ans = -1, mid;
	while(lo <= hi) {
		mid = (hi - lo) / 2 + lo;
		if(v[mid] > target) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}

int lis() {
	for(int i = 0; i < m; i++) {
		int idx = bs(arr[i]);
		if(idx == -1)
			v.push_back(arr[i]);
		else
			v[idx] = arr[i];
	}
	return v.size();
}

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, w, h;
	cin >> tc;
	while(tc--) {
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> w >> h;
			inp[i] = { w, h };
		}
		sort(inp, inp + m, comp);
		for(int i = 0; i < m; i++)
			arr[i] = inp[m - 1 - i].second;
		v.clear();
		cout << lis() << '\n';
	}
	return 0;
}
