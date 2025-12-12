class Solution {
public:
    int romanToInt(string s) {
        int val[256] = {};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && val[s[i]] < val[s[i + 1]])
                ans -= val[s[i]];
            else
                ans += val[s[i]];
        }

        return ans;
    }
};
