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
    set<int> s;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i] != 0){
            s.insert(v[i]);
        }
    }
    vector<int> not_in_arr;
    for(int i=1; i<=n; i++){
        if(s.count(i) == 0){
            not_in_arr.pb(i);
        }
    }
    sort(all(not_in_arr));
    int l = -1;
    int r = -1;
    for(int i=0; i<n; i++){
        if(v[i] == 0){
            v[i] = not_in_arr.back();
            not_in_arr.pop_back();
        }
        if(v[i] != i+1){
            if(l == -1){
                l = i;
            }
            r = i;
        }
    }
    if(l == -1){
        cout << 0 << endl;
    }else{
        cout << r - l + 1 << endl;
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