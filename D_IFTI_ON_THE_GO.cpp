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
const int maxN = 2e5;
int n, k, p;
vector<int> v(maxN);

bool isPossible(int mid){
    int curr = 0;
    int cnt = 0;
    while(curr + mid < p){
        int idx = upper_bound(v.begin(), v.begin() + n, curr + mid) - v.begin();
        idx--;
        if(idx < 0) break;
        curr = v[idx];
        cnt++;
        if(idx + 1 < n && curr + mid < v[idx+1]) break;
        if(idx == n-1 && curr + mid < p) break;
    }
    curr += mid;
    if(curr >= p && cnt <= k){
        return true;
    }else{
        return false;
    }
}

void solve(int tc) {
    cin >> n >> k >> p;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int low = 0, high = p;
    while(high - low > 1){
        int mid = low + (high - low)/2;
        if(isPossible(mid)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    if(isPossible(low)){
        cout << low << endl;
    }else{
        cout << high << endl;
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