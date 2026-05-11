class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(auto it:nums)
        {
            vector<int> temp;
            while(it>0)
            {
                int digit=it%10;
                temp.push_back(digit);
                it/=10;
            }
            // reverse(temp.begin(),temp.end());
            for(int j=temp.size()-1;j>=0;j--)
            {
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};