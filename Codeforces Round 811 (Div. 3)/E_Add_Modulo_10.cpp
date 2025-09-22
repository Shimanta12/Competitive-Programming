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

bool isSecondLastDigitEven(int n){
    if(n < 10) return true;
    n/=10;
    return n%2 == 0;
}

void solve(int tc) {
    int n;
    cin >> n;

    vector<int> v(n);
    set<int> st;
    int cnt = 0;

    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]%10 == 0){
            st.insert(v[i]);
            cnt++;
        }
        if(v[i]%10 == 5){
            st.insert(v[i] + 5);
            cnt++;
        }
    }

    if(st.size() > 1){
        cout << "No" << endl;
        return;
    }
    if(st.size() == 1 && cnt==n){
        cout << "Yes" << endl;
        return;
    }
    if(cnt > 0 && cnt != n){
        cout << "No" << endl;
        return;
    }

    map<int, int> even;
    map<int, int> odd;

    for(int i=0; i<n; i++){
        set<int> e, o;
        for(int j=0; j<10; j++){
            if(isSecondLastDigitEven(v[i])){
                e.insert(v[i]%10);
            }else{
                o.insert(v[i]%10);
            }
            v[i] += v[i]%10;
        }
        for(int elem : e){
            even[elem]++;
        }
        for(int elem : o){
            odd[elem]++;
        }
    }

    for(auto pr : even){
        if(pr.second == n){
                cout << "Yes" << endl;
                return;
            }
        }
        
        for(auto pr : odd){
        if(pr.second == n){
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
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