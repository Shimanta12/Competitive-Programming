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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        ans += __builtin_popcountll(v[i]);
    }
    vector<int> hsh(65);
    for(int i=0; i<n; i++){
        for(int j=0; j<65; j++){
            ll x = v[i] & (1ll << j); 
            if(x == 0){
                hsh[j]++;
            }
        }
    }
    ll pow = 1;
    for(int i=0; i<64; i++){
        ll cnt = hsh[i];
        // bug(cnt);
        ll req = cnt*pow;
        // bug(i, req);
        if(k >= req){
            ans += cnt;
            k -= req;
        }else{
            ans += k/pow;
            break;
        }
        pow *= 2;
    }
    cout << ans << endl;
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