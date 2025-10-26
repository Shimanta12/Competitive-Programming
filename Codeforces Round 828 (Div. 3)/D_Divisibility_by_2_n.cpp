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
    vi v(n+1);
    int cnt = 0;
    for(int i=1, x; i<=n; i++){
        cin >> v[i];
        while(v[i] % 2 == 0){
            cnt++;
            v[i]/=2;
        }
    }
    if(cnt >= n){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    vector<int> aa;
    for(int i=2; i<=n; i+=2){
        int temp = i;
        int cnt = 0;
        while(temp % 2 == 0){
            cnt++;
            temp/=2;
        }
        aa.pb(cnt);
    }
    sort(all(aa), greater());
    for(int i=0; i<aa.size(); i++){
        cnt += aa[i];
        if(cnt >= n){
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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