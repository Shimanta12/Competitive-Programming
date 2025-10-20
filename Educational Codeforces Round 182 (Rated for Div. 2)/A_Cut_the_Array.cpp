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
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + v[i];
    }
    for(int l = 1; l<=n; l++){
        for(int r = l+1; r <= n; r++){
            int s1 = prefix[l] % 3;
            int s2 = (prefix[r] - prefix[l]) % 3;
            int s3 = (prefix[n] - prefix[r]) % 3;
            if(s1 == s2 && s2 == s3){
                cout << l << " " << r << endl;
                return;
            }
            if(s1 != s2 && s2 != s3 && s1 != s3){
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << "0 0" << endl;
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