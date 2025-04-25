class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
         unordered_map<int, long long> countMap;
    countMap[0] = 1; // initial prefix mod count
    long long res = 0;
    int cnt = 0;

    for (int num : nums) {
        if (num % modulo == k) {
            cnt++;
        }
        int currMod = cnt % modulo;
        int targetMod = (currMod - k + modulo) % modulo;

        res += countMap[targetMod];
        countMap[currMod]++;
    }

    return res;
    }
};