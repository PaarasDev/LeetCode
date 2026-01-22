class Solution {
public:
    bool sorted(const vector<int>& a) {
        for (int i = 1; i < a.size(); i++)
            if (a[i] < a[i-1]) return false;
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!sorted(nums)) {
            int idx = 0;
            int minSum = nums[0] + nums[1];

            for (int i = 1; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i+1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }

        return ops;
    }
};
