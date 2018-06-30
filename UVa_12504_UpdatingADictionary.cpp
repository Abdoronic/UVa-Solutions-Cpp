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
    int t;
    string line1, line2;
    cin >> t;
    getline(cin , line1);
    while(t--) {
        getline(cin, line1);
        getline(cin, line2);
        line1 = line1.substr(1, line1.length()-2);
        line2 = line2.substr(1, line2.length()-2);
        for(char& c : line1)
            if(c == ':' || c == ',')
                c = ' ';
        for(char& c : line2)
            if(c == ':' || c == ',')
                c = ' ';
        map<string, string> map1;
        map<string, string> map2;
        istringstream ss(line1);
        string p1, p2;
        while(ss >> p1 >> p2)
            map1.insert({p1, p2});
        ss = istringstream(line2);
        while(ss >> p1 >> p2)
            map2.insert({p1, p2});
        vector<string> added;
        vector<string> removed;
        vector<string> changed;
        for(auto i : map1) {
            string key = i.first;
            if(map2.find(key) != map2.end()) {
                if(map1[key] != map2[key])
                    changed.pb(key);
            } else {
                removed.pb(key);
            }
        }
        for(auto i : map2) {
            string key = i.first;
            if(map1.find(key) == map1.end())
                added.pb(key);
        }
        if(added.size() == 0 && removed.size() == 0 && changed.size() == 0) {
            cout << "No changes\n\n";
            continue;
        }
        for(int i = 0; i < added.size(); i++)
            cout << (i==0? "+" : "") << added[i] << (i==added.size()-1? "\n" : ",");
        for(int i = 0; i < removed.size(); i++)
            cout << (i==0? "-" : "") << removed[i] << (i==removed.size()-1? "\n" : ",");
        for(int i = 0; i < changed.size(); i++)
            cout << (i==0? "*" : "") << changed[i] << (i==changed.size()-1? "\n" : ",");
        cout << '\n';
    }
    return 0;
}
