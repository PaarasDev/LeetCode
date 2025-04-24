class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
          int n = nums.size();
    
    // Step 1: Count total distinct elements in the array
    unordered_set<int> totalSet(nums.begin(), nums.end());
    int totalDistinct = totalSet.size();
    
    int count = 0;
    unordered_map<int, int> freq;
    int left = 0;

    // Step 2: Use sliding window from left to right
    for (int right = 0; right < n; ++right) {
        freq[nums[right]]++;

        // While current window has all distinct elements
        while (freq.size() == totalDistinct) {
            // Count how many subarrays start from left and go till >= right
            count += (n - right);
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                freq.erase(nums[left]);
            left++;
        }
    }
        return count;
    }
};