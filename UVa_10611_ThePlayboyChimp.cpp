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

int N;
int arr[50005];

inline int getlower(int target) {
	int lo = 0, hi = N-1, ans = -1, mid;
	while(lo <= hi) {
		mid = lo + (hi - lo)/2;
		if(arr[mid] < target) {
			ans = arr[mid];
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

inline int gethigher(int target) {
	int lo = 0, hi = N-1, ans = -1, mid;
	while(lo <= hi) {
		mid = lo + (hi - lo)/2;
		if(arr[mid] > target) {
			ans = arr[mid];
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	int q, h;
	cin >> q;
	while(q--) {
		cin >> h;
		int low = getlower(h);
		int high = gethigher(h);
		if(low < 0)
			cout << 'X' << ' ';
		else
			cout << low << ' ';
		if(high < 0)
			cout << 'X' << '\n';
		else
			cout << high << '\n';
	}
	return 0;
}
