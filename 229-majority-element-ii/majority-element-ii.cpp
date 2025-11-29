class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,v1=0,v2=1;
        int n=nums.size();
         for(int x:nums)
         {
            if (x==v1) c1++;
            else if (x==v2) c2++;
            else if (c1==0) v1=x,c1=1;
            else if (c2==0) v2=x, c2=1;
            else c1--, c2--;
         }
         c1=c2=0;
         for(int x:nums)
         {
            if(x==v1) c1++;
            else if (x==v2) c2++;
         }
         vector<int> ans;
         if(c1>n/3) ans.push_back(v1);
         if(c2>n/3) ans.push_back(v2);
         return ans;
    }
};