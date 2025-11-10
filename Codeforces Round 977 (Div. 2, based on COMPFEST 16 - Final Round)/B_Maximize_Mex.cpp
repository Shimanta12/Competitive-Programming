#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 2e9;
const double PI = acos(-1);

int d[8][2] = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}, { -1, -1}, { -1, 1}, {1, 1}, {1, -1}};

#define int             long long

#define endl           "\n"

#define vi             vector<int>
#define pb             push_back
#define all(x)         begin(x), end(x)
#define sz(x)          (int)(x).size()

#define pi             pair<int, int>
#define F              first
#define S              second

#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int calc_mex(map<int, int> &mp, int mx){
    for(int i=0; i<=mx+1; i++){
        if(mp.find(i) == mp.end()){
            return i;
        }
    }
}

void solve(int tc) {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for(int i=0, val; i<n; i++){
        cin >> val;
        mp[val]++;
    }
    // at worst case the mex of an array will be equal to 'n'
    int mex = calc_mex(mp, n);
    
    for(auto pr : mp){
        if(pr.first > mex){
            cout << mex << endl;
            return;
        }else if(pr.first == mex){
            mex = pr.first+1;
        }
        if(pr.second > 1){
            mp[pr.first + x] += mp[pr.first]-1;
            mp[pr.first] = 1;
        }
    }
    cout << mex << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}