class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& list, vector< vector<int>>& ans,int k)
    {
        if(list.size()==k)
        {
            ans.push_back(vector<int> (list));
            return ;
        }
        if(i==nums.size())
        {
            return ;
        }
        else{
            list.push_back(nums[i]);
            solve(i+1,nums,list,ans,k);
            list.pop_back();
            solve(i+1,nums,list,ans,k);
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
         vector< vector<int>> ans;
          vector<int> list;
        solve(0,nums,list,ans,k);
        return ans;
    }
};