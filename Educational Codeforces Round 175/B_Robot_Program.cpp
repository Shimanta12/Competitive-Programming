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
    ll n, x, k;
    cin >> n >> x >> k;

    string s;
    cin >> s;

    ll ans = 0;
    int mn = min(n, k);
    int i;
    for(i=0; i<mn; i++){
        if(s[i] == 'L'){
            x-=1;
        }else{
            x+=1;
        }
        k--;
        if(x==0){
            ans++;
            break;
        }
    }
    if(k == 0){
        cout << ans << endl;
    }else{
        int cnt = -1;
        mn = min(n, k);
        if(ans) i=0;
        for(; i<mn; i++){
            if(s[i] == 'L'){
                x--;
            }else{
                x++;
            }
            k--;
            if(x==0){
                ans++;
                cnt = i+1;
                break;
            }
        }
        if(cnt != -1){
            ans += k/cnt;
        }
        cout << ans << endl;
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