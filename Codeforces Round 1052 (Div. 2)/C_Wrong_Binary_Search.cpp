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
    string s;
    cin >> s;
    if(s[0] == '0' && s[1] == '1'){
        cout << "NO" << endl;
        return;
    }
    vector<int> ans(n);
    int x = n;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '1'){
            ans[i] = i+1;
            int cnt = 0;
            for(int j=i+1; j<n; j++){
                if(s[j] == '1') break;
                ans[j] = x--;
                cnt++;
            }
            if(cnt==1){
                cout << "NO" << endl;
                return;
            }
            x = i;
        }
    }
    cout << "YES" << endl;
    for(int i=0; i<n; i++){
        if(ans[i] == 0){
            ans[i] = x--;
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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