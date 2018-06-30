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

inline bool pot(int i, int j) {
    int x = i ^ j;
    int count = 0;
    while(x) {
        x -= (x & (-x));
        count++;
        if(count > 1)
            return false;
    }
    return count == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while(cin >> N) {
        int limit = pow(2, N);
        int weight[limit];
        for(int i = 0; i < limit; i++)
            cin >> weight[i];
        int arr[limit];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < limit; i++) {
            for(int j = i+1; j < limit; j++) {
                if(pot(i, j)) {
                    arr[i] += weight[j];
                    arr[j] += weight[i];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < limit; i++) {
            for(int j = i+1; j < limit; j++) {
                if(pot(i, j)) {
                    ans = max(ans, arr[i] + arr[j]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}