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
const int mxN = 1e6;
vector<bool> isPrime(mxN + 1, true);
vector<int> primes;

void solve(int tc) {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for(int i=0, x; i<n; i++){
        cin >> x;
        set<int> s;
        for(int j=0; j<primes.size(); j++){
            bool f = false;
            while(x % primes[j] == 0){
                f = true;
                x /= primes[j];
            }
            if(f){
                s.insert(primes[j]);
            }
        }
        int j=0;
        for(int e : s){
            if(e != primes[j]){
                ans = min(ans, primes[j]);
                break;
            }
            j++;
        }
        ans = min(ans, primes[j]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    isPrime[0] = isPrime[1] = false;
    int prod = 1;
    for(int i=2; i<=mxN; i++){
        if(isPrime[i]){
            primes.pb(i);
            prod *= i;
            if(prod > 1e18) break;
            for(int j=i*2; j<=mxN; j+=i){
                isPrime[j] = false;
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