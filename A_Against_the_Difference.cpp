#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 2e9;
const double PI = acos(-1);

int d[8][2] = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}, { -1, -1}, { -1, 1}, {1, 1}, {1, -1}};

#define ll             long long

#define endl           "\n"

#define vi             vector<int>
#define pb             push_back
#define all(x)         begin(x), end(x)
#define sz(x)          (int)(x).size()

#define pi             pair<int, int>
#define F              first
#define S              second
#define mp             make_pair

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

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> v(n+1), prefix(n+1), suffix(n+2);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    map<int, int> mp;
    map<int, vector<int>> pos;
    for(int i=1; i<=n; i++){
        mp[v[i]]++;
        pos[v[i]].pb(i);
        if(mp[v[i]]>=v[i]){
            int left_out = mp[v[i]]%v[i];
            int cnt = mp[v[i]] - left_out;
            prefix[i] = max(prefix[i-1], cnt + prefix[pos[v[i]][left_out] - 1]);
        }else{
            prefix[i] = prefix[i-1];
        }
    }
    mp.clear();
    pos.clear();
    for(int i=n; i>=1; i--){
        mp[v[i]]++;
        pos[v[i]].pb(i);
        if(mp[v[i]]>=v[i]){
            int left_out = mp[v[i]]%v[i];
            int cnt = mp[v[i]] - left_out;
            suffix[i] = max(suffix[i+1], cnt + suffix[pos[v[i]][left_out] + 1]);
        }else{
            suffix[i] = suffix[i+1];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, prefix[i] + suffix[i+1]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}