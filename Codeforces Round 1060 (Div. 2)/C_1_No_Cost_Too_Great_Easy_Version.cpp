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

const int mxN = 2e5 + 1;
vector<bool> isPrime(mxN, true);
vector<int> lp(mxN);

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0, x; i<n; i++){
        cin >> x;
    }
    map<int, int> mp;
    for(int i=0; i<n; i++){
        set<int> factors;
        int num = v[i];
        while(num > 1){
            factors.insert(lp[num]);
            num /= lp[num];
        }
        for(int e : factors){
            mp[e]++;
        }
    }
    for(auto pr : mp){
        if(pr.second > 1){
            cout << 0 << endl;
            return;
        }
    }
    for(int i=0; i<n; i++){
        set<int> factors;
        int num = v[i]+1;
        while(num > 1){
            factors.insert(lp[num]);
            num /= lp[num];
        }
        for(int e : factors){
            if(mp.count(e)){
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<mxN; i++){
        if(isPrime[i]){
            lp[i] = i;
            for(int j=i*2; j<mxN; j+=i){
                isPrime[j] = false;
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }

    int tc = 1;
    
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}