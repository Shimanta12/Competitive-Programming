# C++ Quick Reference for Competitive Programming

## Table of Contents
1. [Template & Fast I/O](#template--fast-io)
2. [Data Types & Limits](#data-types--limits)
3. [STL Containers](#stl-containers)
4. [Algorithms & Searching](#algorithms--searching)
5. [String Operations](#string-operations)
6. [Math Functions](#math-functions)
7. [Bit Manipulation](#bit-manipulation)
8. [Graph Algorithms](#graph-algorithms)
9. [Dynamic Programming](#dynamic-programming)
10. [Number Theory](#number-theory)
11. [Advanced Data Structures](#advanced-data-structures)
12. [Common Patterns](#common-patterns)

---

## Template & Fast I/O

### Standard Contest Template
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    // Your code here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
```

### Fast Input/Output
```cpp
// Fast I/O (use at start of main)
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

// Read entire line
string s;
getline(cin, s);

// Read until EOF
int x;
while(cin >> x) {
    // process x
}

// Read multiple values
int a, b, c;
cin >> a >> b >> c;

// Output with precision
cout << fixed << setprecision(10) << 3.14159265359;

// Flush output
cout << answer << endl;  // Flushes
cout << answer << "\n";  // Faster, doesn't flush
```

---

## Data Types & Limits

### Type Ranges
```cpp
int           // -2,147,483,648 to 2,147,483,647 (~2e9)
long long     // -9,223,372,036,854,775,808 to 9e18
unsigned int  // 0 to 4,294,967,295 (~4e9)
unsigned ll   // 0 to 18,446,744,073,709,551,615 (~18e18)

// Constants
INT_MAX       // 2,147,483,647
INT_MIN       // -2,147,483,648
LLONG_MAX     // 9,223,372,036,854,775,807
LLONG_MIN     // -9,223,372,036,854,775,808

// Size of types
sizeof(int)       // 4 bytes
sizeof(long long) // 8 bytes
sizeof(char)      // 1 byte
sizeof(double)    // 8 bytes
```

### Type Aliases
```cpp
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

// Modern C++ (preferred)
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
```

---

## STL Containers

### Vector
```cpp
// Declaration
vector<int> v;
vector<int> v(10);
vector<int> v(10, 5);
vector<int> v = {1, 2, 3, 4, 5};
vector<vector<int>> grid(n, vector<int>(m, 0));

// Modification
v.push_back(x);
v.pop_back();
v.insert(v.begin() + i, x);
v.erase(v.begin() + i);
v.clear();
v.resize(n);

// Access
v[i];
v.at(i);
v.front();
v.back();

// Information
v.size();
v.empty();

// Iteration
for(int x : v) { }
for(int i = 0; i < v.size(); i++) { }
```

### Pair & Tuple
```cpp
// Pair
pair<int, int> p = {3, 5};
p.first;
p.second;

// Tuple
tuple<int, int, int> t = {1, 2, 3};
get<0>(t);
int a, b, c;
tie(a, b, c) = t;
```

### Set
```cpp
set<int> s;

s.insert(x);
s.erase(x);
s.count(x);
s.find(x);
s.size();
s.empty();

auto it = s.lower_bound(x);
auto it = s.upper_bound(x);

*s.begin();
*s.rbegin();
```

### Multiset
```cpp
multiset<int> ms;

ms.insert(5);
ms.count(5);
ms.erase(5);              // Removes ALL
ms.erase(ms.find(5));     // Remove one
```

### Map
```cpp
map<string, int> mp;

mp["key"] = value;
mp.count("key");
mp.erase("key");
mp.size();

for(auto &[key, val] : mp) {
    // process
}
```

### Unordered Map
```cpp
unordered_map<int, int> ump;
// O(1) average, no ordering
```

### Stack
```cpp
stack<int> st;

st.push(x);
st.pop();
st.top();
st.empty();
st.size();
```

### Queue
```cpp
queue<int> q;

q.push(x);
q.pop();
q.front();
q.back();
q.empty();
q.size();
```

### Priority Queue
```cpp
// Max heap (default)
priority_queue<int> maxpq;

// Min heap
priority_queue<int, vector<int>, greater<int>> minpq;

pq.push(x);
pq.top();
pq.pop();
```

### Deque
```cpp
deque<int> dq;

dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.pop_front();
dq[i];
```

---

## Algorithms & Searching

### Sorting
```cpp
vector<int> v = {3, 1, 4, 1, 5};

sort(all(v));
sort(v.rbegin(), v.rend());
sort(all(v), greater<int>());

// Custom comparator
sort(all(v), [](int a, int b) {
    return abs(a) < abs(b);
});

// Check if sorted
is_sorted(all(v));

// Stable sort
stable_sort(all(v));
```

### Binary Search
```cpp
vector<int> v = {1, 2, 3, 4, 5};

bool found = binary_search(all(v), 4);

auto it = lower_bound(all(v), 4);  // First >= 4
auto it = upper_bound(all(v), 4);  // First > 4

int idx = lower_bound(all(v), 4) - v.begin();
```

### Min/Max
```cpp
int a = 5, b = 10;

int minimum = min(a, b);
int maximum = max(a, b);
int minimum = min({a, b, c});

vector<int> v = {3, 1, 4};
int minVal = *min_element(all(v));
int maxVal = *max_element(all(v));

// Clamp
int x = clamp(value, lo, hi);
```

### Other Algorithms
```cpp
reverse(all(v));
rotate(v.begin(), v.begin() + k, v.end());

#include <numeric>
int sum = accumulate(all(v), 0);
ll sum = accumulate(all(v), 0LL);

int cnt = count(all(v), x);
int cnt = count_if(all(v), [](int x) { return x > 3; });

auto it = find(all(v), x);

sort(all(v));
v.erase(unique(all(v)), v.end());

fill(all(v), 7);
replace(all(v), 1, 99);

// Permutations
do {
    // process
} while(next_permutation(all(v)));
```

---

## String Operations

### Basic Operations
```cpp
string s = "hello";

s.length();
s.size();
s.empty();
s[i];
s.front();
s.back();

s.push_back('!');
s.pop_back();
s += " world";
s.append(" world");
s.insert(5, " there");
s.erase(5, 6);
s.clear();

string sub = s.substr(0, 5);
string sub = s.substr(6);

size_t pos = s.find("world");
if(pos != string::npos) { }

reverse(all(s));
sort(all(s));
```

### Conversion
```cpp
// String to number
string s = "123";
int n = stoi(s);
long long ll = stoll(s);
double d = stod(s);

// Number to string
string s = to_string(123);
```

### Character Functions
```cpp
#include <cctype>

isalpha(c);
isdigit(c);
isalnum(c);
islower(c);
isupper(c);
isspace(c);

char lower = tolower(c);
char upper = toupper(c);

int val = c - '0';
int val = c - 'a';
```

### String Parsing
```cpp
// Split by whitespace
stringstream ss(s);
string word;
while(ss >> word) { }

// Split by delimiter
stringstream ss(s);
string token;
while(getline(ss, token, ',')) { }
```

---

## Math Functions

### Basic Math
```cpp
#include <cmath>

abs(-5);
fabs(-5.5);
pow(2, 3);
sqrt(16);
cbrt(27);

ceil(3.2);
floor(3.8);
round(3.5);
trunc(3.9);

log(x);
log10(x);
log2(x);
exp(x);

sin(x);
cos(x);
tan(x);

M_PI;
M_E;
```

### Integer Math
```cpp
// GCD
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int g = __gcd(12, 18);

// LCM
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Prime check
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Sieve
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// Prime factorization
vector<int> primeFactors(int n) {
    vector<int> factors;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factors.push_back(n);
    return factors;
}
```

### Modular Arithmetic
```cpp
const int MOD = 1e9 + 7;

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b) {
    return ((ll)(a % MOD) * (b % MOD)) % MOD;
}

// Power
ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Modular inverse
ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

// Factorial precomputation
vector<ll> fact, invFact;
void precompute(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invFact[n] = modInverse(fact[n], MOD);
    for(int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if(r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % MOD) * invFact[n-r] % MOD;
}
```

---

## Bit Manipulation

### Basic Operations
```cpp
int x = 5;  // 101

// Check bit
bool isSet = (x >> i) & 1;

// Set bit
x |= (1 << i);

// Clear bit
x &= ~(1 << i);

// Toggle bit
x ^= (1 << i);

// Check odd
bool isOdd = x & 1;

// Check power of 2
bool isPower2 = (x > 0) && ((x & (x - 1)) == 0);

// Multiply/divide by 2^k
x << k;
x >> k;
```

### Built-in Functions
```cpp
__builtin_popcount(x);
__builtin_popcountll(x);
__builtin_clz(x);
__builtin_ctz(x);
__builtin_ffs(x);
__builtin_parity(x);
```

### Common Tricks
```cpp
// XOR properties
a ^ a = 0;
a ^ 0 = a;

// Rightmost set bit
x & (-x);

// Remove rightmost set bit
x & (x - 1);

// Find unique element
int unique = 0;
for(int x : arr) unique ^= x;

// Iterate subsets
for(int mask = 0; mask < (1 << n); mask++) {
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) {
            // i is in subset
        }
    }
}
```

---

## Graph Algorithms

### Graph Representation
```cpp
// Adjacency list
vector<int> adj[n];
vector<pair<int, int>> adj[n];  // weighted

// Add edge
adj[u].push_back(v);
adj[u].push_back({v, w});

// Adjacency matrix
int adj[n][n];
```

### DFS
```cpp
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Iterative DFS
void dfsIterative(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
}
```

### BFS
```cpp
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}
```

### Dijkstra
```cpp
vector<pii> adj[MAX];
int dist[MAX];

void dijkstra(int start, int n) {
    fill(dist, dist + n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        if(d > dist[node]) continue;
        
        for(auto [neighbor, weight] : adj[node]) {
            int newDist = dist[node] + weight;
            if(newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
}
```

### Bellman-Ford
```cpp
struct Edge {
    int u, v, weight;
};

vector<Edge> edges;
int dist[MAX];

bool bellmanFord(int start, int n) {
    fill(dist, dist + n, INF);
    dist[start] = 0;
    
    for(int i = 0; i < n - 1; i++) {
        for(auto &e : edges) {
            if(dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
    }
    
    // Check negative cycle
    for(auto &e : edges) {
        if(dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
            return false;
        }
    }
    return true;
}
```

### Floyd-Warshall
```cpp
int dist[MAX][MAX];

void floydWarshall(int n) {
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
```

### Topological Sort
```cpp
// Kahn's algorithm
vector<int> topologicalSort(int n) {
    vector<int> result;
    queue<int> q;
    
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result;
}

// DFS-based
void dfsTopo(int node) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfsTopo(neighbor);
        }
    }
    result.push_back(node);
}
```

### Cycle Detection
```cpp
// Undirected
bool hasCycleDFS(int node, int parent) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(hasCycleDFS(neighbor, node)) return true;
        } else if(neighbor != parent) {
            return true;
        }
    }
    return false;
}

// Directed
int color[MAX];
bool hasCycleDirected(int node) {
    color[node] = 1;
    for(int neighbor : adj[node]) {
        if(color[neighbor] == 1) return true;
        if(color[neighbor] == 0 && hasCycleDirected(neighbor)) return true;
    }
    color[node] = 2;
    return false;
}
```

### Minimum Spanning Tree

#### Kruskal
```cpp
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int parent[MAX];

int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int kruskal(vector<Edge>& edges, int n) {
    sort(all(edges));
    for(int i = 0; i < n; i++) parent[i] = i;
    
    int mstWeight = 0;
    for(auto &e : edges) {
        if(find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            mstWeight += e.weight;
        }
    }
    return mstWeight;
}
```

#### Prim
```cpp
vector<pii> adj[MAX];
bool inMST[MAX];

int prim(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    int mstWeight = 0;
    while(!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if(inMST[node]) continue;
        
        inMST[node] = true;
        mstWeight += weight;
        
        for(auto [neighbor, w] : adj[node]) {
            if(!inMST[neighbor]) {
                pq.push({w, neighbor});
            }
        }
    }
    return mstWeight;
}
```

---

## Dynamic Programming

### 1D DP
```cpp
// Fibonacci
int fib(int n) {
    if(n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Climbing stairs
int climbStairs(int n) {
    if(n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// House robber
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}
```

### 2D DP
```cpp
// LCS
int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// Edit distance
int editDistance(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}

// 0/1 Knapsack
int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], 
                               dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
```

### Kadane's Algorithm
```cpp
int maxSubarraySum(vector<int>& arr) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
```

### Coin Change
```cpp
// Minimum coins
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Number of ways
int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for(int coin : coins) {
        for(int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}
```

---

## Number Theory

### Primes
```cpp
// Check prime
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Sieve
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// Prime factorization
map<int, int> primeFactorize(int n) {
    map<int, int> factors;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if(n > 1) factors[n]++;
    return factors;
}
```

### GCD & LCM
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Extended Euclidean
int extgcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
```

### Euler's Totient Function
```cpp
int phi(int n) {
    int result = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
    return result;
}
```

---

## Advanced Data Structures

### Disjoint Set Union (DSU)
```cpp
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### Segment Tree
```cpp
class SegmentTree {
    vector<int> tree;
    int n;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    void updateUtil(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if(idx <= mid) {
                updateUtil(2*node, start, mid, idx, val);
            } else {
                updateUtil(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    int queryUtil(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return queryUtil(2*node, start, mid, l, r) + 
               queryUtil(2*node+1, mid+1, end, l, r);
    }
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    
    void update(int idx, int val) {
        updateUtil(1, 0, n - 1, idx, val);
    }
    
    int query(int l, int r) {
        return queryUtil(1, 0, n - 1, l, r);
    }
};
```

### Fenwick Tree (BIT)
```cpp
class FenwickTree {
    vector<int> tree;
    int n;
public:
    FenwickTree(int n) : n(n) {
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        idx++;
        while(idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    int query(int idx) {
        idx++;
        int sum = 0;
        while(idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    
    int query(int l, int r) {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
```

### Sparse Table
```cpp
class SparseTable {
    vector<vector<int>> st;
    vector<int> log;
    int n;
public:
    SparseTable(vector<int>& arr) {
        n = arr.size();
        int maxLog = log2(n) + 1;
        st.assign(n, vector<int>(maxLog));
        log.assign(n + 1, 0);
        
        for(int i = 2; i <= n; i++) {
            log[i] = log[i/2] + 1;
        }
        
        for(int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        for(int j = 1; j < maxLog; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    int query(int l, int r) {
        int len = r - l + 1;
        int k = log[len];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};
```

### Trie
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};
```

### Monotonic Stack
```cpp
// Next greater element
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// Previous greater element
vector<int> previousGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if(!st.empty()) result[i] = arr[st.top()];
        st.push(i);
    }
    return result;
}

// Largest rectangle in histogram
int largestRectangle(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        int h = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, h * width);
    }
    
    return maxArea;
}
```

### Sliding Window Maximum
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    
    for(int i = 0; i < nums.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}
```

---

## Common Patterns

### Two Pointers
```cpp
// Check palindrome
bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

// Two sum (sorted array)
pair<int, int> twoSum(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum == target) return {l, r};
        if(sum < target) l++;
        else r--;
    }
    return {-1, -1};
}

// Container with most water
int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxArea = 0;
    while(l < r) {
        maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
        if(height[l] < height[r]) l++;
        else r--;
    }
    return maxArea;
}

// Remove duplicates
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int j = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
}
```

### Sliding Window
```cpp
// Max sum subarray of size k
int maxSumK(vector<int>& arr, int k) {
    int sum = 0;
    for(int i = 0; i < k; i++) sum += arr[i];
    
    int maxSum = sum;
    for(int i = k; i < arr.size(); i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// Longest substring with k distinct chars
int longestKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int l = 0, maxLen = 0;
    
    for(int r = 0; r < s.length(); r++) {
        freq[s[r]]++;
        
        while(freq.size() > k) {
            freq[s[l]]--;
            if(freq[s[l]] == 0) freq.erase(s[l]);
            l++;
        }
        
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// Longest substring without repeating
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int l = 0, maxLen = 0;
    
    for(int r = 0; r < s.length(); r++) {
        if(lastSeen.count(s[r])) {
            l = max(l, lastSeen[s[r]] + 1);
        }
        lastSeen[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
```

### Prefix Sum
```cpp
// Build prefix sum
vector<int> prefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    return prefix;
}

// Range sum [l, r]
int rangeSum(vector<int>& prefix, int l, int r) {
    return prefix[r + 1] - prefix[l];
}

// 2D prefix sum
vector<vector<int>> build2DPrefix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + 
                          prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    return prefix;
}

// 2D range sum
int query2D(vector<vector<int>>& prefix, int r1, int c1, int r2, int c2) {
    return prefix[r2+1][c2+1] - prefix[r1][c2+1] - 
           prefix[r2+1][c1] + prefix[r1][c1];
}

// Subarray sum equals K
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0, count = 0;
    
    for(int num : nums) {
        sum += num;
        if(prefixCount.count(sum - k)) {
            count += prefixCount[sum - k];
        }
        prefixCount[sum]++;
    }
    return count;
}
```

### Binary Search on Answer
```cpp
// Find minimum x where check(x) is true
int binarySearch(int lo, int hi) {
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// Find maximum x where check(x) is true
int binarySearchMax(int lo, int hi) {
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}
```

### Coordinate Compression
```cpp
vector<int> compress(vector<int>& arr) {
    vector<int> sorted = arr;
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());
    
    for(int &x : arr) {
        x = lower_bound(all(sorted), x) - sorted.begin();
    }
    return arr;
}
```

### Matrix Operations
```cpp
// Matrix multiplication
vector<vector<int>> matMul(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    vector<vector<int>> C(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Matrix exponentiation
vector<vector<ll>> matPow(vector<vector<ll>> mat, ll n) {
    int sz = mat.size();
    vector<vector<ll>> result(sz, vector<ll>(sz, 0));
    
    for(int i = 0; i < sz; i++) result[i][i] = 1;
    
    while(n > 0) {
        if(n & 1) result = matMul(result, mat);
        mat = matMul(mat, mat);
        n >>= 1;
    }
    return result;
}
```

### Common Tricks
```cpp
// Direction vectors
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 8 directions
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Check valid index
bool valid = (i >= 0 && i < n && j >= 0 && j < m);

// Random number
#include <random>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random = uniform_int_distribution<int>(L, R)(rng);

// Measure time
auto start = chrono::high_resolution_clock::now();
// Code
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
cout << "Time: " << duration.count() << " ms\n";

// Fast input (competitive)
inline void fastRead(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; c < 48 || c > 57; c = getchar_unlocked()) {
        if(c == '-') neg = 1;
    }
    for(; c > 47 && c < 58; c = getchar_unlocked()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(neg) x = -x;
}
```

---

## Quick Reference

### Time Complexities
```
O(1)        - Hash map, array access
O(log n)    - Binary search, balanced BST
O(n)        - Linear search, single pass
O(n log n)  - Sorting, merge sort
O(n²)       - Nested loops
O(n³)       - Triple nested loops
O(2^n)      - Subsets, backtracking
O(n!)       - Permutations
```

### Constraint Guidelines
```
n ≤ 10      → O(n!), O(2^n)
n ≤ 20      → O(2^n), O(n² × 2^n)
n ≤ 500     → O(n³)
n ≤ 5000    → O(n²)
n ≤ 10^6    → O(n log n), O(n)
n ≤ 10^8    → O(n), O(log n)
n ≤ 10^18   → O(log n), O(1)
```

### Pro Tips
1. Check edge cases: empty, single element, duplicates
2. Use `long long` when values exceed 2×10^9
3. Apply modulo at each step to avoid overflow
4. Integer division: use `a + (b-a)/2` to avoid overflow
5. Floating point comparison: `abs(a - b) < 1e-9`
6. Vector size is unsigned, be careful in loops
7. `memset()` only works for 0 and -1
8. Use `assert()` for debugging
9. Always use fast I/O in competitive programming
10. Read problem constraints carefully

---

**Remember:** Practice makes perfect. Save this reference for contests!