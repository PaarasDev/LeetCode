class Solution {
public:
    // Function to count set bits in a number
    int countBits(long long n) {
        int bits = 0;
        while (n > 0) {
            bits += (n & 1);  // add 1 if last bit is set
            n >>= 1;          // shift right
        }
        return bits;
    }

    int makeTheIntegerZero(int num1, int num2) {
        // Try different number of operations (k)
        for (int k = 1; k <= 60; k++) {
            long long val = (long long)num1 - (long long)k * num2;

            // If value becomes negative or smaller than k, skip
            if (val < k) continue;

            // Count how many set bits are in 'val'
            int bits = countBits(val);

            // If we can split 'val' into exactly k parts, return k
            if (bits <= k) return k;
        }

        // If no solution found
        return -1;
    }
};
