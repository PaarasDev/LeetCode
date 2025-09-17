class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        string word;
        stringstream ss(text);

        while (ss >> word) {
            bool valid = true;
            for (char c : word) {
                if (broken.count(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
        }
        return count;
    }
};
