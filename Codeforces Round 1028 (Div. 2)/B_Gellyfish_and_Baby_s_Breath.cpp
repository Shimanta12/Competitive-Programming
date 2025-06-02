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
const int M = 998244353;
const int mxN = 1e5;
vector<int> powers(mxN);

void power(){
    powers[0] = 1;
    for(int i=1; i<mxN; i++){
        powers[i] = (powers[i-1] * 1ll * 2)%M;
    }
}

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    for(int i=0; i<n; i++){
        cin >> q[i];
    }
    int p_mx = 0;
    int q_mx = 0;
    vector<int> r(n);
    for(int i=0; i<n; i++){
        if(p[i] > p[p_mx]){
            p_mx = i;
        }
        if(q[i] > q[q_mx]){
            q_mx = i;
        }
        vector<int> v = {p[p_mx], q[i-p_mx], q[q_mx], p[i-q_mx]};
        sort(all(v), greater<int>());
        if(v[0] == v[1]){
            r[i] = (powers[v[0]] + 0ll + powers[max(v[2], v[3])])%M;
        }else{
            if(v[0] == p[p_mx]){
                r[i] = (powers[p[p_mx]] + 0ll + powers[q[i - p_mx]])%M;
            }else{
                r[i] = (powers[q[q_mx]] + 0ll + powers[p[i - q_mx]])%M;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << r[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    power();
    int tc = 1;
    
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}