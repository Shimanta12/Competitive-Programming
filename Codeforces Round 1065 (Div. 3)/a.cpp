#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 1000000007;
const int INF = LLONG_MAX;
const double PI = acos(-1);

void solve(int tc) {
    #ifndef ONLINE_JUDGE
        cout << "Case #" << tc << ": ";
    #endif
    vector<string> v = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string s;
    cin >> s;
    int k;
    cin >> k;
    k%=12;
    int idx = -1;
    for(int i=0; i<12; i++){
        if(v[i] == s){
            idx = i;
            break;
        }
    }
    for(int i=0; i<k; i++){
        idx++;
        if(idx==12){
            idx=0;
        }
    }
    cout << v[idx] << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}