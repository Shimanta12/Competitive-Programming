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

int pow(int n){
    int x = 2;
    int ans = 1;
    while(n > 0){
        if(n&1){
            ans = (ans*1ll*x)%MOD;
        }
        x = (x*1ll*x)%MOD;
        n>>=1;
    }
    return ans;
}

void solve(int tc) {
    int t;
    cin >> t;
    vector<pair<int, int>> v(t);
    for(int i=0; i<t; i++){
        cin >> v[i].first;
    }
    for(int i=0; i<t; i++){
        cin >> v[i].second;
    }
    for(int i=0; i<t; i++){
        if(v[i].first == v[i].second){
            cout << 1 << endl;
        }else{
            cout << pow(v[i].second) << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}