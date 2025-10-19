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
    int n;
    cin >> n;

    int sum1, sum2;
    cout << 1 << " " << 1 << " " << n << endl;
    cout.flush();

    cin >> sum1;
    cout << 2 << " " << 1 << " " << n << endl;
    cout.flush();
    cin >> sum2;

    int len = sum2 - sum1;

    int low = 0, high = n-1;
    int l = 0;
    while(low <= high){
        int mid = (low + high)/2;
        cout << 1 << " " << low + 1 << " " << mid+1 << endl;
        cout.flush();
        int real;
        cin >> real;
        cout << 2 << " " << low + 1 << " " << mid+1 << endl;
        cout.flush();
        int fake;
        cin >> fake;
        if(real == fake){
            low = mid + 1;

        }else{
            high = mid - 1;
            l = mid;
        }
    }
    int r = l+len-1; 
    
    cout << "! " << l+1 << " " << r+1 << endl;
    cout.flush();
}

//2 4 5 1

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