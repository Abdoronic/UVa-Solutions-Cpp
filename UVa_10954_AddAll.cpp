#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

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
    while(true) {
        cin >> n;
        if(n == 0) break;
        int tmp;
        priority_queue<int> q;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            q.push(-tmp);
        }
        int sum;
        ll ans = 0;
        while(q.size() > 1) {
            sum = 0;
            sum += (-q.top());
            q.pop();
            sum += (-q.top());
            q.pop();
            q.push(-sum);
            ans += sum;
        }
        cout << ans << '\n';
    }
    return 0;
}

