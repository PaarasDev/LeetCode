class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int sum=(n*(n+1))/2;
        for(int i:nums)
        {
            x+=i;
        }
        return (sum-x);
    }
};