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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll mn = LLONG_MAX;
    for(int i=0; i<n; i++){
        cin >> v[i];
        mn = min(mn, v[i]);
    }
    if(k >= 3){
        cout << 0 << endl;
    }else{
        vector<ll> possible_elem;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                possible_elem.pb(abs(v[i] - v[j]));
            }
        }
        sort(all(possible_elem));
        if(k==1){
            cout << min(mn, possible_elem[0]) << endl;
        }else{
            mn = min(mn, possible_elem[0]);
            sort(all(v));
            for(int i=0; i<possible_elem.size(); i++){
                auto it = lower_bound(all(v), possible_elem[i]);
                if(it != v.end()){
                    mn = min(mn, abs((*it) - possible_elem[i]));
                }
            }
            for(int i=0; i<n; i++){
                auto it = lower_bound(all(possible_elem), v[i]);
                if(it != possible_elem.end()){
                    mn = min(mn, abs((*it) - v[i]));
                }
            }
            cout << mn << endl;
        }
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