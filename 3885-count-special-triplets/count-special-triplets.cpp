class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<long long, long long> right, left;
        
        for (long long x : nums) right[x]++;
        
        long long ans = 0;
        
        for (long long j = 0; j < nums.size(); j++) {
            long long val = nums[j];
            right[val]--;
            
            long long need = val * 2;
            ans = (ans + left[need] * right[need]) % MOD;
            
            left[val]++;
        }
        
        return ans;
    }
};
