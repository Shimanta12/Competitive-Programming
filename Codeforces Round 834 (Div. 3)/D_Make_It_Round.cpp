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
    int n, m;
    cin >> n >> m;
    int cnt1 = 0, cnt2 = 0;
    int p = 2;
    while(n % p == 0){
        cnt1++;
        p*=2;
    }
    p = 5;
    while(n % p == 0){
        cnt2++;
        p*=5;
    }
    ll ans = n;
    if(cnt1 < cnt2){
        int k = 2;
        while(cnt1 < cnt2){
            if(k <= m){
                cnt1++;
                k*=2;
            }else{
                break;
            }
        }
        k/=2;
        m/=k;
        ans *= k;
    }else if(cnt2 < cnt1){
        int k = 5;
        while(cnt2 < cnt1){
            if(k <= m){
                cnt2++;
                k*=5;
            }else{
                break;
            }
        }
        k/=5;
        m/=k;
        ans *= k;
    }
    p = 10;
    while(m / p != 0){
        p*=10;
        ans*=10;
    }
    p/=10;
    m/=p;

    cout << ans * m << endl;
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