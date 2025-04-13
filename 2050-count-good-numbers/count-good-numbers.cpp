class Solution {
public:
    long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        long long evenWays = modPow(5, evenPos);
        long long oddWays = modPow(4, oddPos);
        return (evenWays * oddWays) % mod;
    }
};
