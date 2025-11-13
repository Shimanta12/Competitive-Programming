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
        bool useBinMul;
        bool isPrimeMod;
        
        Math() {}
        
        Math(int n, T modVal = MOD, bool useBinaryMul = false, bool modIsPrime = true) : N(n), MOD_VAL(modVal), useBinMul(useBinaryMul), isPrimeMod(modIsPrime) {
            fact.resize(n);
            invfact.resize(n);
            
            fact[0] = 1;
            for (int i = 1; i < n; i++) {
                if (useBinMul) {
                    fact[i] = binMul(fact[i-1], i, MOD_VAL);
                } else {
                    fact[i] = mod(fact[i-1] * i, MOD_VAL);
                }
            }
            
            invfact[n-1] = modinv(fact[n-1], MOD_VAL);
            for (int i = n-2; i >= 0; i--) {
                if (useBinMul) {
                    invfact[i] = binMul(invfact[i+1], i+1, MOD_VAL);
                } else {
                    invfact[i] = mod(invfact[i+1] * (i+1), MOD_VAL);
                }
            }
        }
        
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
        
        T extGCD(T a, T b, T &x, T &y) {
            if (b == 0) {
                x = 1;
                y = 0;
                return a;
            }
            T x1, y1;
            T gcd = extGCD(b, a % b, x1, y1);
            x = y1;
            y = x1 - (a / b) * y1;
            return gcd;
        }
        
        T modInverseExtGCD(T a, T m) {
            T x, y;
            T gcd = extGCD(a, m, x, y);
            if (gcd != 1) {
                return -1;
            }
            return (x % m + m) % m;
        }
        
        T modinv(T x, T m) {
            if (isPrimeMod) {
                return expo(x, m - 2, m);
            } else {
                return modInverseExtGCD(x, m);
            }
        }
        
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
        
        T lcm(T a, T b) {
            return (a / __gcd(a, b)) * b;
        }
        
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