class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        vector<long long> left(n), right(n);
        left[0] = arr[0];
        for (int i = 1; i < n; ++i) left[i] = max<long long>(arr[i], left[i-1] + arr[i]);
        right[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; --i) right[i] = max<long long>(arr[i], right[i+1] + arr[i]);
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) ans = max(ans, left[i]);            // no deletion
        for (int i = 0; i < n; ++i) {
            if (i == 0) ans = max(ans, right[1]);
            else if (i == n-1) ans = max(ans, left[n-2]);
            else ans = max(ans, left[i-1] + right[i+1]);                // delete arr[i]
        }
        return (int)ans;
    }
};
