class Solution {
public:
    string ans = "";
    int count = 0;

    void dfs(int n, int k, string curr)
    {
        if(curr.size() == n)
        {
            count++;
            if(count == k)
                ans = curr;
            return;
        }

        for(char c : {'a','b','c'})
        {
            if(curr.empty() || curr.back() != c)
            {
                dfs(n, k, curr + c);
                if(!ans.empty()) return;
            }
        }
    }

    string getHappyString(int n, int k) 
    {
        dfs(n, k, "");
        return ans;
    }
};
