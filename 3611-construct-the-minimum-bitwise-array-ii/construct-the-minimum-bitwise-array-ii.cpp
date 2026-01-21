class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            if (p == 2) {
                ans.push_back(-1);
                continue;
            }

            int k = 0;
            int t = p;
            while (t & 1) {
                k++;
                t >>= 1;
            }

            int x = p - (1 << (k - 1));
            ans.push_back(x);
        }

        return ans;
    }
};
