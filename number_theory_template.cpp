#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
// const ll LARGE_MOD = 1e18 + 7; // Use this for problems with large modulus
const int MAXN = 1e6 + 5;

// ======================== BASIC MATH FUNCTIONS ========================

// Binary multiplication for large modulus (like 1e18+7)
// Prevents overflow when a*b might exceed long long range
ll mul_mod(ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    b %= mod;
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % mod;
        }
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}

// Regular modular multiplication (faster for smaller mod values)
ll mod_mul(ll a, ll b, ll mod) {
    return ((a % mod) * (b % mod)) % mod;
}

// Fast modular exponentiation with binary multiplication for large mod
ll power(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            if (mod > 3e9) result = mul_mod(result, base, mod);
            else result = (result * base) % mod;
        }
        if (mod > 3e9) base = mul_mod(base, base, mod);
        else base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Alternative: Force binary multiplication regardless of mod size
ll power_large_mod(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = mul_mod(result, base, mod);
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Modular multiplicative inverse using Fermat's little theorem
// Only works when mod is prime
ll mod_inverse(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod);
}

// Extended Euclidean Algorithm
// Returns gcd(a, b) and finds x, y such that ax + by = gcd(a, b)
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Modular multiplicative inverse using extended GCD
// Works for any mod (not necessarily prime)
ll mod_inverse_extended(ll a, ll mod) {
    ll x, y;
    ll gcd = extended_gcd(a, mod, x, y);
    if (gcd != 1) return -1; // Inverse doesn't exist
    return (x % mod + mod) % mod;
}

// ======================== SIEVE AND PRIME FUNCTIONS ========================

vector<bool> is_prime(MAXN, true);
vector<int> primes;
vector<int> spf(MAXN); // smallest prime factor

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 0; i < MAXN; i++) spf[i] = i;
    
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            spf[i] = i;
            for (ll j = (ll)i * i; j < MAXN; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
}

// Check if a number is prime (Miller-Rabin for large numbers)
bool miller_test(ll d, ll n) {
    ll a = 2 + rand() % (n - 4);
    ll x = power_large_mod(a, d, n);
    if (x == 1 || x == n - 1) return true;
    
    while (d != n - 1) {
        x = mul_mod(x, x, n);
        d *= 2;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool is_prime_large(ll n, int k = 5) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    
    for (int i = 0; i < k; i++) {
        if (!miller_test(d, n)) return false;
    }
    return true;
}

// Prime factorization using precomputed spf
vector<pii> prime_factors(int n) {
    vector<pii> factors;
    while (n > 1) {
        int p = spf[n];
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        factors.push_back({p, cnt});
    }
    return factors;
}

// Prime factorization for large numbers
vector<pll> prime_factors_large(ll n) {
    vector<pll> factors;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}

// ======================== DIVISOR FUNCTIONS ========================

// Count of divisors
vector<int> divisor_count(MAXN, 0);

void precompute_divisor_count() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisor_count[j]++;
        }
    }
}

// Sum of divisors
vector<ll> divisor_sum(MAXN, 0);

void precompute_divisor_sum() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisor_sum[j] += i;
        }
    }
}

// Get all divisors of n
vector<int> get_divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

// ======================== EULER'S TOTIENT FUNCTION ========================

vector<int> phi(MAXN);

void compute_phi() {
    for (int i = 0; i < MAXN; i++) phi[i] = i;
    
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j < MAXN; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

// Euler's totient function for a single number
ll euler_phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// ======================== MOBIUS FUNCTION ========================

vector<int> mu(MAXN);

void compute_mobius() {
    mu[1] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 2 * i; j < MAXN; j += i) {
            mu[j] -= mu[i];
        }
    }
}

// ======================== COMBINATORICS ========================

vector<ll> fact(MAXN), inv_fact(MAXN);

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv_fact[MAXN-1] = mod_inverse(fact[MAXN-1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n-r] % MOD;
}

ll nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[n-r]) % MOD;
}

// ======================== CHINESE REMAINDER THEOREM ========================

// Solve system: x ≡ a[i] (mod m[i])
// Returns {solution, lcm of all moduli} or {-1, -1} if no solution
pll chinese_remainder_theorem(vector<ll> &a, vector<ll> &m) {
    int n = a.size();
    ll x = a[0], lcm = m[0];
    
    for (int i = 1; i < n; i++) {
        ll a1 = x, m1 = lcm;
        ll a2 = a[i], m2 = m[i];
        
        ll g = __gcd(m1, m2);
        if ((a2 - a1) % g != 0) return {-1, -1};
        
        ll p, q;
        extended_gcd(m1 / g, m2 / g, p, q);
        
        ll mod = lcm / g * m2;
        x = ((a1 + m1 * ((a2 - a1) / g * p % (m2 / g))) % mod + mod) % mod;
        lcm = mod;
    }
    
    return {x, lcm};
}

// ======================== DISCRETE LOGARITHM ========================

// Baby-step Giant-step algorithm
// Finds x such that a^x ≡ b (mod m)
ll discrete_log(ll a, ll b, ll m) {
    ll n = sqrt(m) + 1;
    
    unordered_map<ll, ll> vals;
    ll cur = 1;
    for (ll i = 0; i < n; i++) {
        if (vals.find(cur) == vals.end()) {
            vals[cur] = i;
        }
        cur = mul_mod(cur, a, m);
    }
    
    ll factor = mod_inverse(power_large_mod(a, n, m), m);
    ll gamma = b;
    for (ll i = 0; i < n; i++) {
        if (vals.find(gamma) != vals.end()) {
            ll ans = vals[gamma] + i * n;
            if (ans < m) return ans;
        }
        gamma = mul_mod(gamma, factor, m);
    }
    
    return -1; // No solution
}

// ======================== UTILITY FUNCTIONS ========================

// GCD and LCM
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Check if a number is perfect square
bool is_perfect_square(ll n) {
    ll root = sqrt(n);
    return root * root == n;
}

// Sum of digits
int digit_sum(ll n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// ======================== MAIN FUNCTION TEMPLATE ========================

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Uncomment the functions you need
    // sieve();
    // compute_phi();
    // compute_mobius();
    // precompute_factorials();
    // precompute_divisor_count();
    // precompute_divisor_sum();
    
    int t;
    cin >> t;
    while (t--) {
        // Your solution here
    }
    
    return 0;
}

/*
Usage Examples:

1. Fast exponentiation: 
   - power(2, 10, MOD) - automatically handles large mod
   - power_large_mod(2, 10, LARGE_MOD) - forces binary multiplication
2. Modular multiplication:
   - mod_mul(a, b, MOD) - for regular mod values (≤ 10^9)
   - mul_mod(a, b, LARGE_MOD) - binary multiplication for large mod (≥ 10^18)
3. Modular inverse: mod_inverse(5, MOD)
4. Prime check: is_prime[n] or is_prime_large(n)
5. Prime factors: prime_factors(n) or prime_factors_large(n)
6. Divisors: get_divisors(n)
7. Euler's totient: phi[n] or euler_phi(n)
8. Combinations: nCr(n, r), nPr(n, r)
9. CRT: chinese_remainder_theorem(a, m)
10. Discrete log: discrete_log(a, b, m)

Time Complexities:
- Sieve: O(N log log N)
- Power: O(log exp) - uses binary multiplication when mod > 3×10^9
- Binary multiplication (mul_mod): O(log b)
- Regular multiplication (mod_mul): O(1)
- Prime factorization: O(sqrt(N))
- Miller-Rabin: O(k log^3 N)
- Euler's totient: O(N log log N) preprocessing, O(sqrt(N)) single
- CRT: O(N log(max moduli))

Notes:
- power() automatically switches to binary multiplication for mod > 3×10^9
- Use mul_mod() for large modulus values like 10^18 + 7
- Use mod_mul() for typical contest constraints (mod ≤ 10^9)
- Binary multiplication prevents overflow when a*b exceeds long long range
*/