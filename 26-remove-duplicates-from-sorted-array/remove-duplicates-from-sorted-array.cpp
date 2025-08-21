class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        if(n<2)
        {
            return n;
        }
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                arr.push_back(nums[i]);
            }
        }
        
        int k=arr.size();
        for(int i=0;i<k;i++)
        {
            nums[i]=arr[i];
        }
        return k;
    }
};