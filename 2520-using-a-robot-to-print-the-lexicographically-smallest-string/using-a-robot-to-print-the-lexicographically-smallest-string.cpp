class Solution {
public:
    string robotWithString(string s) {
        vector<int> last_occurrence(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string t, result;
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            count[s[i] - 'a']--;

            while (!t.empty()) {
                char smallest_remaining = 'z' + 1;
                for (int c = 0; c < 26; ++c) {
                    if (count[c] > 0) {
                        smallest_remaining = c + 'a';
                        break;
                    }
                }

                if (t.back() <= smallest_remaining) {
                    result += t.back();
                    t.pop_back();
                } else {
                    break;
                }
            }
        }

        return result;
    }
};
