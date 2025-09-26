class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] + nums[j] > nums[k] &&
                        nums[i] + nums[k] > nums[j] &&
                        nums[j] + nums[k] > nums[i]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
