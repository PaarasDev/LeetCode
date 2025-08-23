class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m=0,cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
            }
            m=max(m,cnt);
            if(nums[i]==0)
            {
                cnt=0;
            }
        }
        return m;
    }
};