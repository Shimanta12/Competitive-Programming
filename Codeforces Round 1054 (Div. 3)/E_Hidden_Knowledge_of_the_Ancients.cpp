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
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    map<int, int> mp;
    set<int> st;
    ll ans = 0;
    int l=0, r = 0;
    while(l < n){
        st.insert(v[r]);
        mp[v[r]]++;
        if(st.size() == k){
            int len = r - l + 1;
            if(len > y){
                mp[v[r]]--;
                if(mp[v[r]] == 0){
                    st.erase(mp[v[r]]);
                }
                mp[v[l]]--;
                if(mp[v[l]] == 0){
                    st.erase(v[l]);
                }
                l++;
            }else if(len >= x){
                ans++;
                r++;
            }
        }else if(st.size() > k){
            mp[v[l]]--;
            if(mp[v[l]] == 0){
                st.erase(v[l]);
            }
            l++;
        }else{
            r++;
        }
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