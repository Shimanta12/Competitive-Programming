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

int trailingZero(string &s){
    int cnt = 0;
    int i=s.size()-1;
    while(i >= 0 && s[i] == '0'){
        cnt++;
        i--;
    }
    return cnt;
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(all(v), [&](string &a, string &b){
        int x = trailingZero(a);
        int y = trailingZero(b);
        return x > y;
    });
    int len = 0;
    for(int i=0; i<n; i++){
        if(i%2==0){
            len += v[i].size() - trailingZero(v[i]);
        }else{
            len += v[i].size();
        }
    }
    if(len >= m+1){
        cout << "Sasha" << endl;
    }else{
        cout << "Anna" << endl;
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