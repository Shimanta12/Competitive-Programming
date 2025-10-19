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
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    int a_cnt = log2(a) + 1;
    int b_cnt = log2(b) + 1;
    if(b_cnt > a_cnt){
        cout << -1 << endl;
    }else{
        int mask = 0;
        for(int i=0; i<31; i++){
            if(b & (1 << i)){
                if((a & (1 << i)) == 0){
                    mask |= (1<<i);
                }
            }else{
                if(a & (1<<i)){
                    mask |= (1<<i);
                }
            }
        }
        if(mask <= a){
            cout << 1 << endl << mask << endl;
        }else{
            int x = log2(mask);
            mask &= (~(1 << x));
            cout << 2 << endl << mask << " " << (1 << x) << endl;
        }
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