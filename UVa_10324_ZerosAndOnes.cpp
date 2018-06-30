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
    int n, l, r, t1, t2;
    string line;
    for(int i = 1; getline(cin, line) && !line.empty(); i++) {
        cin >> n;
        cout << "Case "<< i << ":\n";
        while(n--) {
            cin >> t1 >> t2;
            l = min(t1, t2);
            r = max(t1, t2);
            int count = 0;
            for(int j = l; j <= r; j++)
                if(line[j] == '1') count++;
            cout << (count == 0 || count == r - l + 1? "Yes": "No") << '\n';
        }
        getline(cin, line);
    }
    return 0;
}
