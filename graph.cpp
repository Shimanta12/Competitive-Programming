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
const int mxN = 1e5 + 10;

//unweighted
vector<vector<int>> graph(mxN);

//weighted
// vector<vector<pair<int, int>>> graph(mxN);

//visited vector
vector<bool> visited(mxN);

// parent
vector<int> parent(mxN);
int n, m;

bool dfs(int curr, int par){
    // take action on vertex after entering the vertex
    visited[curr] = true;
    for(int adj : graph[curr]){
        if(!visited[adj]){
            // take action on child node before entering the child node
            bool hasCycle = dfs(adj, curr);
            // take action on child node after exiting the child node
            if(hasCycle) return true;
        }else{
            if(adj != par){
                return true;
            }
        }
    }
    // take action on vertex before exiting the vertex
    return false;
}

void solve(int tc) {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    // 1-indexed
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool hasCycle = dfs(i, 0);
            if(hasCycle){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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

/*
//Unweighted
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6

// weighted
6 9
1 3 4
1 5 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2
5 6 3

*/