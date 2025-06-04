class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        for (int i = 0; i < s.size(); ++i)
            lastIndex[s[i] - 'a'] = i;

        vector<bool> seen(26, false);
        string result;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (seen[c - 'a'])
                continue;

            while (!result.empty() && c < result.back() && lastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            seen[c - 'a'] = true;
        }

        return result;
    }
};
