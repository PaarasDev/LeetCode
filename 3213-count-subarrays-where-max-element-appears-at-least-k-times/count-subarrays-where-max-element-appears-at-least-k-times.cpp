class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    
    long long ans = 0;
    int count = 0, left = 0;
    
    for (int right = 0; right < n; ++right) {
        if (nums[right] == maxVal) count++;
        
        while (count >= k) {
            // All subarrays starting from 'left' to 'right' and ending at any position right or later are valid
            ans += (n - right);
            if (nums[left] == maxVal) count--;
            left++;
        }
    }
    
    return ans;
}
};