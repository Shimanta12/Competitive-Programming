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
    vector<int> hsh(31);
    bool all_zero = true;
    for(int i=0, x; i<n; i++){
        cin >> x;
        if(x != 0){
            all_zero = false;
        }
        for(int j=0; j<=30; j++){
            if(x & (1<<j)){
                hsh[j]++;
            }
        }
    }
    if(all_zero){
        for(int i=1; i<=n; i++){
            cout << i << " ";
        }
        cout << endl;
    }else{
        int gosagu = 0;
        for(int i=0; i<31; i++){
            gosagu = __gcd(gosagu, hsh[i]);
        }
        if(gosagu == 0){
            cout << 1 << endl;
            return;
        }
        vector<int> divisors;
        for(int i=1; i*i<=gosagu; i++){
            if(gosagu%i == 0){
                divisors.pb(i);
                int x = gosagu/i;
                if(x!=i){
                    divisors.pb(x);
                }
            }
        }
        sort(all(divisors));
        for(int i=0; i<divisors.size(); i++){
            cout << divisors[i] << " ";
        }
        cout << endl;
    }
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