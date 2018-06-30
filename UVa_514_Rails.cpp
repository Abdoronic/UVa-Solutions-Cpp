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
    int N, t;
    while(true) {
        scanf("%d", &N);
        if(N == 0) break;
        int arr[N];
        while(true) {
            scanf("%d", &arr[0]);
            if(arr[0] == 0) break;
            for(int i = 1; i < N; i++)
                scanf("%d", &arr[i]);
            stack<int> station;
            int curr = 1;
            bool flag = true;
            for(int i = 0; i < N;) {
                if(arr[i] == curr) {
                    curr++;
                    i++;
                } else {
                    if(!station.empty() && arr[i] == station.top()) {
                        station.pop();
                        i++;
                    } else {
                        if(curr > N) {
                            flag = false;
                            break;
                        } else {
                            station.push(curr);
                            curr++;
                        }
                    }
                }
            }
            printf("%s\n", flag? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}
