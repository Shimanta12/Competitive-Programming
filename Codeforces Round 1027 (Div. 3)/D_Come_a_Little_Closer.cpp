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
    vector<pair<int, int>> monsters;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        monsters.pb({x,y});
    }
    if(n <=2){
        cout << n << endl;
        return;
    }
    pair<int, int> top_mn = {INT_MAX, INT_MAX}, sec_top_mn = {INT_MAX, INT_MAX};
    pair<int, int> left_mn = {INT_MAX, INT_MAX}, sec_left_mn = {INT_MAX, INT_MAX};
    pair<int, int> bottom_mx = {INT_MIN, INT_MIN}, sec_bottom_mx = {INT_MIN, INT_MIN};
    pair<int, int> right_mx = {INT_MIN, INT_MIN}, sec_right_mx = {INT_MIN, INT_MIN};


    for(int i=0; i<n; i++){
        if(monsters[i].F < top_mn.F){
            sec_top_mn = top_mn;
            top_mn = monsters[i];
        }else if(monsters[i].F < sec_top_mn.F){
            sec_top_mn = monsters[i];
        }
        if(monsters[i].S < left_mn.S){
            sec_left_mn = left_mn;
            left_mn = monsters[i];
        }else if(monsters[i].S < sec_left_mn.S){
            sec_left_mn = monsters[i];
        }
        if(monsters[i].F > bottom_mx.F){
            sec_bottom_mx = bottom_mx;
            bottom_mx = monsters[i];
        }else if(monsters[i].F > sec_bottom_mx.F){
            sec_bottom_mx = monsters[i];
        }
        if(monsters[i].S > right_mx.S){
            sec_right_mx = right_mx;
            right_mx = monsters[i];
        }else if(monsters[i].S > sec_right_mx.S){
            sec_right_mx = monsters[i];
        }
    }
    ll ans = LLONG_MAX;
    for(int i=0; i<n; i++){
        bool f1 = false, f2 = false, f3 = false, f4 = false;
        if(monsters[i] == top_mn){
            swap(top_mn, sec_top_mn);
            f1 = true;
        }
        if(monsters[i] == left_mn){
            swap(left_mn, sec_left_mn);
            f2 = true;
        }
        if(monsters[i] == bottom_mx){
            swap(bottom_mx, sec_bottom_mx);
            f3 = true;
        }
        if(monsters[i] == right_mx){
            swap(right_mx, sec_right_mx);
            f4 = true;
        }
        pair<int, int> x = {top_mn.F, left_mn.S};
        pair<int, int> y = {bottom_mx.F, right_mx.S};
        
        
        ll col = y.S - x.S + 1;
        ll row = y.F - x.F + 1;
        ll cells = row*col;
        if(n <= cells){
            ans = min(ans, cells);
        }else{
            ans = min(ans, cells + min(row,col));
        }
        if(f1) swap(top_mn, sec_top_mn);
        if(f2) swap(left_mn, sec_left_mn);
        if(f3) swap(bottom_mx, sec_bottom_mx);
        if(f4) swap(right_mx, sec_right_mx);
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