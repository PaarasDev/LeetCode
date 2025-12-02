class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0,ans=n;
        for(int i=0;i<n;i++)
        {
            sum=(sum+nums[i])%p;
        }
        int target= sum%p;
        if(target==0)
        {
            return 0;
        }
        unordered_map<int,int> mp;
        int currsum=0;
        mp[0]=-1;
        for(int j=0;j<n;j++)
        {
            currsum=(currsum+nums[j])%p;
            int findsum=(currsum-target+p)%p;   //p is added inside to prevent negative numbers in cas target is greater
            if(mp.find(findsum)!=mp.end())
            {
                ans=min(ans,j-mp[findsum]);
            }
            mp[currsum]=j;
        }
        return ans==n ? -1 : ans;
    }
};