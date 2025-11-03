class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0,count=0;
        for(int i=0;i<n;i++)
        {
            s=0;
            for(int j=i;j<n;j++)
            {
                s+=nums[j];
                if(s==k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};