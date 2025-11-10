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

int m, n;
void dfs(int r, int c, int dist, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(r < 0 || r >= m || c < 0 || c >= n){
        return;
    }
    if(dist < dp[r][c]){
        dp[r][c] = dist;
    }else{
        return;
    }
    dfs(r + grid[r][c], c, dist + 1, grid, dp);
    dfs(r - grid[r][c], c, dist + 1, grid, dp);
    dfs(r, c + grid[r][c], dist + 1, grid, dp);
    dfs(r, c - grid[r][c], dist + 1, grid, dp);
}

void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp){
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 0});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int row = curr.first.first;
        int col = curr.first.second;
        int dist = curr.second;
        if(row + grid[row][col] < m && dist + 1 < dp[row + grid[row][col]][col]){
            dp[row + grid[row][col]][col] = dist + 1;
            q.push({{row+grid[row][col], col}, dist+1});
        }
        if(row - grid[row][col] >= 0 && dist + 1 < dp[row - grid[row][col]][col]){
            dp[row - grid[row][col]][col] = dist + 1;
            q.push({{row-grid[row][col], col}, dist+1});
        }
        if(col + grid[row][col] < n && dist + 1 < dp[row][col + grid[row][col]]){
            dp[row][col + grid[row][col]] = dist + 1;
            q.push({{row, col+grid[row][col]}, dist+1});
        }
        if(col - grid[row][col] >= 0 && dist + 1 < dp[row][col - grid[row][col]]){
            dp[row][col - grid[row][col]] = dist + 1;
            q.push({{row, col-grid[row][col]}, dist+1});
        }
    }
    if(dp[m-1][n-1] == LLONG_MAX){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << dp[m-1][n-1] << endl;
    }
}

void solve(int tc) {
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            grid[i][j] = s[j] - '0';
        }
    }
    vector<vector<int>> dp(m, vector<int>(n, LLONG_MAX));
    bfs(0, 0, grid, dp);
    
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