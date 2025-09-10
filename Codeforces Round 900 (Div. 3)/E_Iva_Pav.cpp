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
    vector<int> v(n+1);
    vector<vector<int>> prefix(n+1, vector<int>(31,0));
    for(int i=1; i<=n; i++){
        cin >> v[i];
        for(int j=0; j<=30; j++){
            if(v[i]& (1<<j)){
                prefix[i][j] = prefix[i-1][j] + 1;
            }else{
                prefix[i][j] = prefix[i-1][j];
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(v[l] < k){
            cout << -1 << " ";
        }else{
            int left = l;
            int right = n;
            while(right - left > 1){
                int mid = left + (right-left)/2;
                int val = 0;
                for(int i=0; i<=30; i++){
                    if(prefix[mid][i] - prefix[l-1][i] == (mid-l+1)){
                        val |= (1<<i);
                    }
                }
                if(val >= k){
                    left = mid;
                }else{
                    right = mid - 1;
                }
            }
            int val = 0;
            for(int i=0; i<=30; i++){
                if(prefix[right][i] - prefix[l-1][i] == (right-l+1)){
                    val |= (1<<i);
                }
            }
            if(val >= k){
                cout << right << " ";
            }else{
                cout << left << " ";
            }
        }
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