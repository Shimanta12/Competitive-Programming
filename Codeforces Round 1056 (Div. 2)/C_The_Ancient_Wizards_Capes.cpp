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
const int mxN = 1e5;
vector<int> v(mxN);

int n;
bool check(string s){
    vector<int> prefix(n), suffix(n);
    for(int i=0; i<n; i++){
        if(i==0){
            prefix[i] = 0;
        }else{
            prefix[i] = prefix[i-1];
        }
        prefix[i] += (s[i] == 'L');
    }
    for(int i=n-1; i>=0; i--){
        if(i == n-1){
            suffix[i] = 0;
        }else{
            suffix[i] = suffix[i+1];
        }
        suffix[i] += (s[i] == 'R');
    }
    for(int i=0; i<n; i++){
        int visible = 1;
        if(i > 0){
            visible += prefix[i-1];
        }
        if(i+1 < n){
            visible += suffix[i+1];
        }
        if(visible != v[i]){
            return false;
        }
    }
    return true;
}


void solve(int tc) {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    string a="L", b="R";
    for(int i=0; i<n-1; i++){
        if(v[i] == v[i+1]){
            if(a.back() == 'L'){
                a.pb('R');
            }else{
                a.pb('L');
            }
            if(b.back() == 'L'){
                b.pb('R');
            }else{
                b.pb('L');
            }
        }else{
            if(abs(v[i] - v[i+1]) > 1){
                cout << 0 << endl;
                return;
            }
            if(a.back() == 'L'){
                a.pb('L');
            }else{
                a.pb('R');
            }
            if(b.back() == 'L'){
                b.pb('L');
            }else{
                b.pb('R');
            }
        }
    }
    int ans = 0;
    if(check(a)){
        ans++;
    }
    if(check(b)){
        ans++;
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