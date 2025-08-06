class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& c) {
        int m=c.size();
        int n=g.size();
        int l=0,r=0,count=0;
        sort(g.begin(),g.end());
        sort(c.begin(),c.end());
        while(l<m && r<n)
        {
            if(g[r]>c[l])
            {
                l++;
            }
            else{
                count++;
                l++;
                r++;
            }
        }
        return count;
    }
};