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
    string n;
    cin >> n;
    int digit_sum = 0;
    int twos = 0, threes = 0;
    for(int i=0; i<n.size(); i++){
        digit_sum += n[i] - '0';
        if(n[i] == '2'){
            twos++;
        }else if(n[i] == '3'){
            threes++;
        }
    }
    for(int i=0; i<=twos; i++){
        for(int j=0; j<=threes; j++){
            digit_sum += i*2;
            digit_sum += j*6;
            if(digit_sum % 9 == 0){
                cout << "YES" << endl;
                return;
            }
            digit_sum -= i*2;
            digit_sum -= j*6;
        }
    }
    cout << "NO" << endl;
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