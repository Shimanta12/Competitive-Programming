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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> ans;
    for(int i=0, x; i<m; i++){
        cin >> x;
        ans.insert(x);
    }
    vector<int> prefix(n);
    for(int i=0; i<n; i++){
        int curr = i-2 >= 0 ? prefix[i-2] : 1;
        if(i-1 >= 0){
            if(s[i-1] == 'A'){
                curr++;
            }else{
                for(int i=curr+1; ; i++){
                    if(ans.find(i) == ans.end()){
                        curr = i;
                        break;
                    }
                }
            }
        }
        if(s[i] == 'A'){
            curr++;
            ans.insert(curr);
        }else{
            for(int i=curr+1; ; i++){
                if(ans.find(i) == ans.end()){
                    curr = i;
                    break;
                }
            }
            ans.insert(curr);
            for(int i=curr+1; ; i++){
                if(ans.find(i) == ans.end()){
                    curr = i;
                    break;
                }
            }
        }
        prefix[i] = curr;
    }
    cout << ans.size() << endl;
    for(int e : ans){
        cout << e << " ";
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