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

// ---------------------------------Unweighted graph------------------------------------------
// const int mxN = 1e5 + 10;
// vector<vector<int>> graph(mxN);
// vector<bool> visited(mxN);
// vector<int> parent(mxN);
// vector<int> level(mxN);

// int n, m;

// void dfs(int curr){
//     // take action on vertex after entering the vertex
//     visited[curr] = true;
//     for(int adj : graph[curr]){
//         if(!visited[adj]){
//             // take action on child node before entering the child node
//             dfs(adj);
//             // take action on child node after exiting the child node
//         }
//     }
//     // take action on vertex before exiting the vertex
// }

// void bfs(int src){
//     queue<int> q;
//     q.push(src);
//     visited[src] = 0;
//     parent[src] = -1;

//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         for(int adj : graph[curr]){
//             if(!visited[adj]){
//                 q.push(adj);
//                 visited[adj] = true;
//                 level[adj] = level[curr] + 1;
//                 parent[adj] = curr;
//             }
//         }
//     }
// }




// // ..........................................Dfs on Tree.......................................
// const int mxN = 1e5 + 10;
// vector<vector<int>> tree(mxN);
// vector<int> height(mxN), depth(mxN), dp(mxN), parent(mxN);
// int n;


// bool tree_dfs(int src){
//     // dp[src] = ;
//     for(int adj : tree[src]){
//         if(adj == parent[src]) continue;
        
//         parent[adj] = src;
//         depth[adj] = depth[src] + 1;
        
//         tree_dfs(adj);
        
//         height[src] = max(height[src], height[adj] + 1);
//         // dp[src] += dp[adj];
//     }
// }




// ---------------------------------------Matrix or Grid----------------------------------
// int mxRow = 1e3 + 5, mxCol = 1e3 + 5;
// vector<vector<int>> grid(mxRow, vector<int>(mxCol));
// vector<vector<bool>> visited(mxRow, vector<bool>(mxCol)); 
// vector<vector<int>> level(mxRow, vector<int>(mxCol));
// vector<vector<pair<int, int>>> parent(mxRow, vector<pair<int, int>>(mxCol));

// int n, m;

// bool is_inside(int x, int y){
//     return x >= 0 && x < n && y >= 0 && y < m;
// }

// void grid_dfs(int x, int y){
//     visited[x][y] = true;

//     // adjust the cnt if diagonals are also considered adjacent
//     for(int i=0; i<4; i++){
//         int new_x = x + d[i][0];
//         int new_y = y + d[i][1];
//         if(is_inside(new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y] == 1){
//             grid_dfs(new_x, new_y);
//         }
//     }
// }

// void grid_bfs(int x, int y){
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     parent[x][y] = {-1,-1};

//     while(!q.empty()){
//         auto curr = q.front();
//         q.pop();
//         int curr_x = curr.first;
//         int curr_y = curr.second;
//         for(int i=0; i<4; i++){
//             int new_x = x + d[i][0];
//             int new_y = y + d[i][1];
//             if(is_inside(new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y] == 1){
//                 q.push({new_x, new_y});
//                 visited[new_x][new_y] = true;
//                 level[new_x][new_y] = level[curr_x][curr_y] + 1;
//                 parent[new_x][new_y] = {curr_x, curr_y};
//             }
//         }
//     }
// }



// --------------------------------------------SSSP on Weighted graph--------------------------------
// const int mxN = 1e5 + 10;
// vector<vector<pair<int, int>>> graph(mxN);
// vector<bool> visited(mxN);
// vector<int> dist(mxN, INT_MAX);
// int n, m;

// void bfs_0_1(int src){
//     deque<int> q;
//     q.push_front(src);
//     dist[src] = 0;

//     while(!q.empty()){
//         int curr = q.front();
//         q.pop_front();

//         for(auto &[adj, cost] : graph[curr]){
//             if(dist[curr] + cost < dist[adj]){
//                 dist[adj] = dist[curr] + cost;
//                 if(cost == 0){
//                     q.push_front(adj);
//                 }else{
//                     q.push_back(adj);
//                 }
//             }
//         }
//     }
// }

// void dijkstra(int src){
//     set<pair<int , int>> s;
//     s.insert({0, src});
//     dist[src] = 0;

//     while(!s.empty()){
//         int curr = s.begin()->second;
//         int cost = s.begin()->first;
//         s.erase(s.begin());

//         if(visited[curr]) continue;
//         visited[curr] = true;

//         for(auto &[adj, cost] : graph[curr]){
//             if(dist[curr] + cost < dist[adj]){
//                 dist[adj] = dist[curr] + cost;
//                 s.insert({dist[adj], adj});
//             }
//         }
//     }
// }

// --------------------------------------------MSSP on Weighted graph--------------------------------
const int mxN = 510;
vector<vector<int>> dist(mxN, vector<int>(mxN, INT_MAX));
void solve(int tc) {
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for(int i=1; i<=n; i++){
        dist[i][i] = 0;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == INT_MAX){
                cout << "I" << " ";
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
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
/*
weighted
6 9
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2

*/