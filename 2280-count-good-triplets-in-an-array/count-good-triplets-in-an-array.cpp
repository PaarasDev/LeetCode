class FenwickTree {
public:
    vector<int> bit;
    int n;

    FenwickTree(int size) : n(size), bit(size + 1) {}

    void update(int index, int delta) {
        for (++index; index <= n; index += index & -index)
            bit[index] += delta;
    }

    int query(int index) {
        int sum = 0;
        for (++index; index > 0; index -= index & -index)
            sum += bit[index];
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; i++)
            mapped[i] = pos[nums1[i]];

        FenwickTree bit1(n), bit2(n);
        vector<int> left(n), right(n);

        // Count how many values before i are smaller
        for (int i = 0; i < n; i++) {
            left[i] = bit1.query(mapped[i] - 1);
            bit1.update(mapped[i], 1);
        }

        // Count how many values after i are greater
        for (int i = n - 1; i >= 0; i--) {
            right[i] = bit2.query(n - 1) - bit2.query(mapped[i]);
            bit2.update(mapped[i], 1);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += (long long)left[i] * right[i];

        return ans;
    }
};
