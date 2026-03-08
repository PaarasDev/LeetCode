class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        string p1 = "", p2 = "";

        for(int i = 0; i < 2*n; i++)
        {
            if(i % 2 == 0)
            {
                p1 += '0';
                p2 += '1';
            }
            else
            {
                p1 += '1';
                p2 += '0';
            }
        }

        int ans = INT_MAX;
        int diff1 = 0, diff2 = 0;
        int l = 0;

        for(int r = 0; r < 2*n; r++)
        {
            if(t[r] != p1[r]) diff1++;
            if(t[r] != p2[r]) diff2++;

            if(r - l + 1 > n)
            {
                if(t[l] != p1[l]) diff1--;
                if(t[l] != p2[l]) diff2--;
                l++;
            }

            if(r - l + 1 == n)
                ans = min(ans, min(diff1, diff2));
        }

        return ans;
    }
};