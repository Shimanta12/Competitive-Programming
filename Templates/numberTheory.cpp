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

int mod(int a, int m = MOD) {
    return a % m;
}

template <class T> class Math {
    public:
        vector<T> fact, invfact;
        vector<int> lp;
        vector<bool> isPrime;
        vector<int> numDivisors;
        vector<int> sumDivisors;
        vector<vector<int>> divisors;
        int N;
        T MOD_VAL;
        bool useBinMul;  // flag for when MOD is large (near 1e18)
        bool isPrimeMod;  // flag for when MOD is prime
        
        Math() {}
        
        Math(int n, T modVal = MOD, bool useBinaryMul = false, bool modIsPrime = true) : N(n), MOD_VAL(modVal), useBinMul(useBinaryMul), isPrimeMod(modIsPrime) {
            fact.resize(n);
            invfact.resize(n);
            
            // Precompute factorials
            fact[0] = 1;
            for (int i = 1; i < n; i++) {
                if (useBinMul) {
                    fact[i] = binMul(fact[i-1], i, MOD_VAL);
                } else {
                    fact[i] = mod(fact[i-1] * i, MOD_VAL);
                }
            }
            
            // Precompute inverse factorials (better method)
            invfact[n-1] = modinv(fact[n-1], MOD_VAL);
            for (int i = n-2; i >= 0; i--) {
                if (useBinMul) {
                    invfact[i] = binMul(invfact[i+1], i+1, MOD_VAL);
                } else {
                    invfact[i] = mod(invfact[i+1] * (i+1), MOD_VAL);
                }
            }
        }
        
        // Binary multiplication for large MOD (near 1e18)
        T binMul(T a, T b, T m) {
            T ans = 0;
            a %= m;
            while (b > 0) {
                if (b & 1) {
                    ans = (ans + a) % m;
                }
                a = (a + a) % m;
                b >>= 1;
            }
            return ans;
        }
        
        // Fast modular exponentiation
        T expo(T base, T exp, T m) {
            T res = 1;
            base %= m;
            while (exp > 0) {
                if (exp & 1) {
                    if (useBinMul) {
                        res = binMul(res, base, m);
                    } else {
                        res = mod(res * base, m);
                    }
                }
                if (useBinMul) {
                    base = binMul(base, base, m);
                } else {
                    base = mod(base * base, m);
                }
                exp >>= 1;
            }
            return res;
        }
        
        // Modular inverse using Fermat's little theorem
        T modinv(T x, T m) { 
            return expo(x, m - 2, m); 
        }
        
        // Binomial coefficient nCr
        T choose(T n, T k) {
            if (k < 0 || k > n)
                return 0;
            T ans = fact[n];
            if (useBinMul) {
                ans = binMul(ans, invfact[n - k], MOD_VAL);
                ans = binMul(ans, invfact[k], MOD_VAL);
            } else {
                ans = mod(ans * invfact[n - k], MOD_VAL);
                ans = mod(ans * invfact[k], MOD_VAL);
            }
            return ans;
        }
        
        // Permutation nPr
        T perm(T n, T k) {
            if (k < 0 || k > n)
                return 0;
            T ans = fact[n];
            if (useBinMul) {
                ans = binMul(ans, invfact[n - k], MOD_VAL);
            } else {
                ans = mod(ans * invfact[n - k], MOD_VAL);
            }
            return ans;
        }
        
        // Sieve of Eratosthenes with lowest prime factor
        void sieve(int mxN) {
            isPrime.assign(mxN + 1, true);
            lp.assign(mxN + 1, 0);
            
            isPrime[0] = isPrime[1] = false;
            for(int i = 2; i <= mxN; i++){
                if(isPrime[i]){
                    lp[i] = i;
                    for(int j = i * 2; j <= mxN; j += i){
                        isPrime[j] = false;
                        if(lp[j] == 0){
                            lp[j] = i;
                        }
                    }
                }
            }
        }
        
        // Prime factorization using lowest prime factor
        // Returns vector of {prime, power}
        vector<pair<int, int>> factorizeLP(int n) {
            vector<pair<int, int>> factors;
            while (n > 1) {
                int p = lp[n];
                int cnt = 0;
                while (n % p == 0) {
                    n /= p;
                    cnt++;
                }
                factors.push_back({p, cnt});
            }
            return factors;
        }
        
        // Get unique prime factors
        vector<int> uniquePrimeFactors(int n) {
            vector<int> primes;
            while (n > 1) {
                int p = lp[n];
                primes.push_back(p);
                while (n % p == 0) {
                    n /= p;
                }
            }
            return primes;
        }
        
        // Precompute divisors, count of divisors, and sum of divisors for all numbers up to n
        void precomputeDivisors(int n) {
            divisors.assign(n + 1, vector<int>());
            numDivisors.assign(n + 1, 0);
            sumDivisors.assign(n + 1, 0);
            
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j += i) {
                    divisors[j].push_back(i);
                    numDivisors[j]++;
                    sumDivisors[j] += i;
                }
            }
        }
        
        // Euler's totient function φ(n) using lowest prime
        int phi(int n) {
            int result = n;
            int temp = n;
            while (temp > 1) {
                int p = lp[temp];
                result -= result / p;
                while (temp % p == 0) {
                    temp /= p;
                }
            }
            return result;
        }
        
        // LCM using built-in __gcd
        T lcm(T a, T b) {
            return (a / __gcd(a, b)) * b;
        }
        
        // Check if n is prime (Miller-Rabin for large n)
        bool isPrimeNum(int n) {
            if (n < 2) return false;
            if (n == 2) return true;
            if (n % 2 == 0) return false;
            
            int d = n - 1;
            int r = 0;
            while (d % 2 == 0) {
                d /= 2;
                r++;
            }
            
            vector<int> witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
            for (int a : witnesses) {
                if (a >= n) continue;
                int x = expo(a, d, n);
                if (x == 1 || x == n - 1) continue;
                
                bool composite = true;
                for (int i = 0; i < r - 1; i++) {
                    x = mod(x * x, n);
                    if (x == n - 1) {
                        composite = false;
                        break;
                    }
                }
                if (composite) return false;
            }
            return true;
        }
};

void solve(int tc) {
    // Example 1: Standard MOD (1e9+7)
    Math<int> m1(1e5 + 1);
    cout << "Standard MOD (1e9+7):\n";
    cout << "C(10, 2) = " << m1.choose(10, 2) << "\n";
    cout << "P(10, 2) = " << m1.perm(10, 2) << "\n\n";
    
    // Example 2: Large MOD (1e18+7) - requires binary multiplication
    const int LARGE_MOD = 1000000000000000007LL;
    Math<int> m2(1e5 + 1, LARGE_MOD, true);  // useBinaryMul = true
    cout << "Large MOD (1e18+7) with binary multiplication:\n";
    cout << "C(10, 2) = " << m2.choose(10, 2) << "\n";
    cout << "P(10, 2) = " << m2.perm(10, 2) << "\n\n";
    
    // Sieve
    m1.sieve(100);
    cout << "Is 97 prime? " << (m1.isPrime[97] ? "Yes" : "No") << "\n";
    cout << "Lowest prime factor of 60: " << m1.lp[60] << "\n\n";
    
    // Prime factorization
    int num = 60;
    auto factors = m1.factorizeLP(num);
    cout << "Prime factorization of " << num << ": ";
    for (auto [p, e] : factors) {
        cout << p << "^" << e << " ";
    }
    cout << "\n";
    
    auto uniquePrimes = m1.uniquePrimeFactors(num);
    cout << "Unique prime factors of " << num << ": ";
    for (int p : uniquePrimes) {
        cout << p << " ";
    }
    cout << "\n\n";
    
    // Precompute divisors
    m1.precomputeDivisors(100);
    cout << "Divisors of 60: ";
    for (int d : m1.divisors[60]) cout << d << " ";
    cout << "\n";
    cout << "Count of divisors: " << m1.numDivisors[60] << "\n";
    cout << "Sum of divisors: " << m1.sumDivisors[60] << "\n\n";
    
    // Euler's totient
    cout << "φ(60) = " << m1.phi(60) << "\n\n";
    
    // LCM using __gcd
    cout << "lcm(48, 18) = " << m1.lcm(48, 18) << "\n";
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