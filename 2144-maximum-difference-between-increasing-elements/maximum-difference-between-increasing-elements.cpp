class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int m=0,n=nums.size(),x=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
        {
            x=nums[i]-nums[j];
            m=max(m,x);
        }
        }
        if(m==0)
        {
            return -1;
        }
        return m;
    }
};