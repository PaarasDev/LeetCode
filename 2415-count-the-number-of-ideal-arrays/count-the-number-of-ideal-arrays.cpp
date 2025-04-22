const int MOD = 1e9 + 7;
const int MAX_N = 10001;
long long modPow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
vector<long long> factorial(MAX_N), invFact(MAX_N);
void precomputeFactorials() {
    factorial[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;

    invFact[MAX_N - 1] = modPow(factorial[MAX_N - 1], MOD - 2, MOD);
    for (int i = MAX_N - 2; i >= 0; --i)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return factorial[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}
class Solution {
public:

    int idealArrays(int n, int maxValue) {
          precomputeFactorials();

    // freq[i][len] = number of multiplicative sequences of length `len` ending in `i`
    vector<vector<int>> freq(maxValue + 1, vector<int>(15, 0));
    for (int i = 1; i <= maxValue; ++i)
        freq[i][1] = 1;

    // DP: build up multiplicative chains
    for (int len = 2; len < 15; ++len) {
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = i * 2; j <= maxValue; j += i) {
                freq[j][len] = (freq[j][len] + freq[i][len - 1]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= maxValue; ++i) {
        for (int len = 1; len < 15; ++len) {
            if (freq[i][len]) {
                ans = (ans + freq[i][len] * comb(n - 1, len - 1) % MOD) % MOD;
            }
        }
    }

    return ans;
    }
};