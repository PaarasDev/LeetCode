class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx=0,min=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<min)
            {
            min=prices[i];
            }
            mx=max(mx,prices[i]-min);
        }
        return mx;
    }
};