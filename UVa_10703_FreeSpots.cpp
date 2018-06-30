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

int W, H, N;
int arr[505][505];

int main() {
    int W, H, N;
    int arr[505][505];
    while(true) {
        scanf("%d%d%d", &W, &H, &N);
        if(W == 0) break;
        int x1, x2, y1, y2;
        memset(arr, 0, sizeof(arr));
        while(N--) {
            scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
            int j1 = min(x1,x2) - 1;
            int j2 = max(x1, x2) - 1;
            int i1 = min(y1, y2) - 1;
            int i2 = max(y1, y2) - 1;
            for(int i = i1; i <= i2; i++)
                for(int j = j1; j <= j2; j++)
                    arr[i][j] = 1;
        }
        scanf("\n");
        int count = 0;
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                if(arr[i][j] == 0)
                    count++;
        if(count == 0)
            printf("There is no empty spots.\n");
        else if(count == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", count);


    }
    return 0;
}