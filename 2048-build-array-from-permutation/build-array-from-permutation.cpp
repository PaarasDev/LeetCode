class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        // Encode new values
        for (int i = 0; i < n; i++) {
            nums[i] += (nums[nums[i]] % n) * n;
        }

        // Extract new values
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }

        return nums;
    }
};
