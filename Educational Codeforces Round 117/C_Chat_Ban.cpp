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

ll k, x;

ll getEmotes(ll mid){
    if(mid <= k){
        return (mid * (mid+1))/2;
    }else{
        ll ans = (k * (k+1))/2;
        ll sum = ((k-1) * k)/2;
        ll extra = (k - 1) - (mid%k);
        sum -= (extra * (extra+1))/2;
        ans += sum;
        return ans;
    }
}

void solve(int tc) {
    cin >> k >> x;
    ll low = 1, high = 2*k - 1;
    while(high - low > 1){
        ll mid = low + (high - low)/2;
        ll emotes = getEmotes(mid);
        if(x > emotes){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    if(x > getEmotes(low)){
        cout << high << endl;
    }else{
        cout << low << endl;
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