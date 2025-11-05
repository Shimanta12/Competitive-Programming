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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(all(v));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
    for(int i=1; i<n; i++){
        int rem = v[i] - v[i-1] - 1;
        if(rem){
            pq.push({rem, {v[i], v[i+1]}});
        }
    }
    int extra = x - v.back();
    int last = x;
    vector<int> ans;
    while(k--){
        int tp = -1;
        if(!pq.empty()){
            tp = (pq.top().second.first + pq.top().second.second )/ 2 - pq.top().second.first;
        }
        if(extra >= tp){
            ans.pb(last);
            last--;
            extra--;
        }else{
            int mid = (pq.top().second.first + pq.top().second.second )/ 2;
            ans.pb(mid);
            if(mid - 1 > pq.top().second.first){
                pq.push({(mid-1) - pq.top().second.first - 1, {pq.top().second.first, mid-1}});
            }
            if(mid + 1 < pq.top().second.second){
                pq.push({pq.top().second.first - (mid + 1) - 1, {mid + 1, pq.top().second.second}});
            }
            pq.pop();
        }
        sort(all(ans));
        for(int e : ans){
            cout << e << " ";
        }
        cout << endl;
    }

    cout << endl;

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