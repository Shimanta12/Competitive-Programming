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
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i = 1; i<n; i++){
        if(abs(v[i] - v[i-1]) <= 1){
            cout << 0 << endl;
            return;
        }
    }
    if(n==2){
        cout << -1 << endl;
    }else{
        for(int i=0; i<n; i++){
            int x = v[i];
            int y = v[i]+1;
            int z = v[i]-1;
            if(i >= 2){
                int mn = min(v[i-2], v[i-1]);
                int mx = max(v[i-2], v[i-1]);
                if((x >= mn && x <= mx) || (y >= mn && y <= mx) || z >= mn && z <= mx){
                    cout << 1 << endl;
                    return;
                }
            }
            if(i < n-2){
                int mn = min(v[i+1], v[i+2]);
                int mx = max(v[i+1], v[i+2]);
                if((x >= mn && x <= mx) || (y >= mn && y <= mx) || z >= mn && z <= mx){
                    cout << 1 << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
    }
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