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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> a_prefix(n+1, vector<int>(26));
    vector<vector<int>> b_prefix(n+1, vector<int>(26));
    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++){
            a_prefix[i][j] = a_prefix[i-1][j];
            b_prefix[i][j] = b_prefix[i-1][j];
        }
        a_prefix[i][a[i-1] - 'a']++;
        b_prefix[i][b[i-1] - 'a']++;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i=0; i<26; i++){
            int cnt1 = a_prefix[r][i] - a_prefix[l-1][i];
            int cnt2 = b_prefix[r][i] - b_prefix[l-1][i];
            if(cnt1 > cnt2){
                ans += cnt1 - cnt2;
            }
        }
        cout << ans << endl;
    }
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