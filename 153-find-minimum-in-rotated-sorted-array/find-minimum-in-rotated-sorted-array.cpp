class Solution {
public:
    int findMin(vector<int>& nums) {
        int r=nums.size()-1;
        int l=0,ans=INT_MAX;
        if(r==0)
        {
            return nums[r];
        }
        while(l<=r)
        {
            int mid=(r+l)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};