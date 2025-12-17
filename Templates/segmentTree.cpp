#include <bits/stdc++.h>
using namespace std;

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

struct SegmentTree{
    int n;
    vector<int> st;

    void init(int _n){
        this->n = _n; 
        st.resize(4*n, 0);
    }
    
    int comb(int a, int b){
        return a + b;
    }
    
    void build(int start, int ending, int node, vector<int> &v){
        if(start == ending){
            st[node] = v[start];
            return;
        }
        int mid = (start + ending)/2;
        build(start, mid, node * 2 + 1, v);
        build(mid + 1, ending, node * 2 + 2, v);
        st[node] = comb(st[node*2+1], st[node*2+2]);
    }
    
    int query(int start, int ending, int l, int r, int node){
        if(start > r || ending < l){
            return 0;
        }
        if(start >= l && ending <= r){
            return st[node];
        }
        int mid = (start + ending)/2;
        int q1 = query(start, mid, l, r, node*2+1);
        int q2 = query(mid+1, ending, l, r, node*2+2);
        return comb(q1, q2);
    }
    
    void update(int start, int ending, int node, int index, int value){
        if(start == ending){
            st[node] = value;
            return;
        }
        int mid = (start + ending) / 2;
        if(index <= mid){
            update(start, mid, node*2+1, index, value);
        }else{
            update(mid+1, ending, node*2+2, index, value);
        }
        st[node] = comb(st[node*2+1], st[node*2+2]);
    }
    
    void build(vector<int> &v){
        build(0, n - 1, 0, v);
    }
    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }
    void update(int index, int value){
        update(0, n-1, 0, index, value);
    }
    
};

const int MOD = 1000000007;
const int INF = INT_MAX;
const double PI = acos(-1);

void solve(int tc) {
    #ifndef ONLINE_JUDGE
        cout << "Case #" << tc << ": ";
    #endif
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    SegmentTree st;
    st.init(n);
    st.build(v);
    
    int q;
    cin >> q;
    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1){
            x--, y--;
            cout << st.query(x, y) << endl;
        }else{
            x--;
            st.update(x, y);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}