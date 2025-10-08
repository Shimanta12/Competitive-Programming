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
    ll p;
    cin >> p;
    vector<int> v(n*2);
    ll total = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        total += v[i];
    }
    
    for(int i=n; i<n*2; i++){
        v[i] = v[i-n];
    }

    ll rem = p % total;

    if(rem == 0){
        cout << "1 " << p/total*n;
        return;
    }
    ll sum = 0;
    int l = 0;
    int start = -1;
    ll ans = LLONG_MAX;
    for(int r=0; r<2*n; r++){
        sum += v[r];
        while(sum - v[l] >= rem){
            sum -= v[l];
            l++;
        }
        if(sum >= rem){
            if(r-l+1 < ans){
                start = (l%n)+1;
                ans = r - l + 1;
            }
        }
    }
    cout << start << " " << p/total * n + ans << endl;
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