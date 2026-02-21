class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int countBits(int n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(countBits(i)))
                ans++;
        }
        return ans;
    }
};
