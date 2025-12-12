class Solution {
public:
    int romanToInt(string s) 
    {
        int ans=0,n=s.length();
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        auto x=mp.find(s[n-1]);
        ans+=x->second;
        for(int i=n-2;i>=0;i--)
        {
         auto curr=mp.find(s[i]);
         auto prev=mp.find(s[i+1]);
            if(curr->second < prev->second)
            {
                ans-=curr->second;
            }
            else{
                ans+=curr->second;
            }
        }
        return ans;
    }
};