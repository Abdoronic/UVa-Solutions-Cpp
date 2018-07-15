#include <bits/stdc++.h>

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

template<typename T>
struct SegmentTree {     // One-based except Input Array
	int N;
	T* input;
	vector<T> lazy;
	vector<T> stree;

	inline T f(T a, T b) { return a + b; }

	void build(int v, int l, int r) {
		if(l == r) {
			stree[v] = input[l - 1];
			return;
		}
		int mid = (l + r) >> 1;
		build(v << 1, l, mid);
		build(v << 1 | 1, mid + 1, r);
		stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
	}

	SegmentTree(T arr[], int n) {
		input = arr;
		N = n;
		int sz = 1;
		while(sz < N)
			sz <<= 1;
		stree.assign(sz << 1, 0);
		lazy.assign(sz << 1, 0);
		build(1, 1, N);
	}

	void updatePoint(int v, int l, int r, int idx, T val) {
		if(l == r) {
			stree[v] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if(idx <= mid)
			updatePoint(v << 1, l, mid, idx, val);
		else
			updatePoint(v << 1 | 1, mid + 1, r, idx, val);
		stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
	}

	void updatePoint(int idx, T val) {  //Input index 1-based
		updatePoint(1, 1, N, idx, val);
	}

	void propagate(int v, int l, int mid, int r) {
		lazy[v << 1] += lazy[v];
		lazy[v << 1 | 1] += lazy[v];
		stree[v << 1] += (mid - l + 1) * lazy[v];
		stree[v << 1 | 1] += (r - mid) * lazy[v];
		lazy[v] = 0;
	}

	void updateRange(int v, int l, int r, int rangeStart, int rangeEnd, T val) {
		if(r < rangeStart || l > rangeStart)
			return;
		if(l >= rangeStart && r <= rangeEnd) {
			stree[v] += (r - l + 1) * val;
			lazy[v] += val;
			return;
		}
		int mid = (l + r) >> 1;
		propagate(v, l, mid, r);
		updateRange(v << 1, l, mid, rangeStart, rangeEnd, val);
		updateRange(v << 1 | 1, mid + 1, r, rangeStart, rangeEnd, val);
		stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
	}

	void updateRange(int l, int r, T val) {
		updateRange(1, 1, N, l, r, val);
	}

	T query(int v, int l, int r, int queryStart, int queryEnd) {
		if(r < queryStart || l > queryEnd)
			return 0; //dummy variable
		if(l >= queryStart && r <= queryEnd)
			return stree[v];
		int mid = (l + r) >> 1;
		propagate(v, l, mid, r);
		T q1 = query(v << 1, l, mid, queryStart, queryEnd);
		T q2 = query(v << 1 | 1, mid + 1, r, queryStart, queryEnd);
		return f(q1, q2);
	}

	T query(int l, int r) {
		return query(1, 1, N, l, r);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x, y;
	while(cin >> n >> m) {
		int arr[n];
		memset(arr, 0, sizeof arr);
		SegmentTree<int> tNeg(arr, n);
		SegmentTree<int> tZero(arr, n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			if(arr[i] < 0)
				tNeg.updatePoint(i + 1, 1);
			if(arr[i] == 0)
				tZero.updatePoint(i + 1, 1);
		}
		char c;
		while(m--) {
			cin >> c >> x >> y;
			if(c == 'C') {
				if(y < 0) {
					tNeg.updatePoint(x, 1);
					tZero.updatePoint(x, 0);
				}else if(y == 0) {
					tNeg.updatePoint(x, 0);
					tZero.updatePoint(x, 1);
				} else {
					tNeg.updatePoint(x, 0);
					tZero.updatePoint(x, 0);
				}
			} else {
				int cntNeg = tNeg.query(x, y);
				int cntZero = tZero.query(x, y);
				if(cntZero >= 1)
					cout << '0';
				else if(cntNeg % 2)
					cout << '-';
				else
					cout << '+';
			}
		}
		cout << '\n';
	}
	return 0;
}
