class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count=1,ans=1;
        int n=prices.size();
        for(int i=0;i<n-1;i++)
        {
            if(prices[i]-1 == prices[i+1])
            {
                count+=1;
            }
            else {
                count=1;
            }
            ans+=count;
        }
        return ans;
    }
};