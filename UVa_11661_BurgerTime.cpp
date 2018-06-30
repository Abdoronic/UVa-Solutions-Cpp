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
    string s;
    while(true) {
        cin >> n;
        if(n == 0)
            break;
        cin >> s;
        if((int)s.find("Z") != -1) {
            cout << 0 << '\n';
            continue;
        }
        int arr[n];
        for(int i = 0; i < n; i++)
            arr[i] = INF;
        int idxR = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'R')
                idxR = i;
            if(s[i] == 'D' && idxR != -1)
                arr[idxR] = min(arr[idxR], i - idxR);
        }
        idxR = -1;
        for(int i = n - 1; i > -1; i--) {
            if(s[i] == 'R')
                idxR = i;
            if(s[i] == 'D' && idxR != -1)
                arr[idxR] = min(arr[idxR], idxR - i);
        }
        cout << *min_element(arr, arr+n) << '\n';
    }
    return 0;
}
