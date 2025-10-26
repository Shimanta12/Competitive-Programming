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

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        ans += v[i];
    }
    while(v.size() > 1){
        int sum = 0;
        for(int i=1; i<v.size(); i++){
            sum += v[i] - v[i-1];
        }
        vector<int> temp;
        for(int i=1; i<v.size(); i++){
            temp.pb(v[i] - v[i-1]);
        }
        v.pop_back();
        for(int i=0; i<temp.size(); i++){
            v[i] = temp[i];
        }
        ans = max(ans, abs(sum));
    }
    cout << ans << endl;
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