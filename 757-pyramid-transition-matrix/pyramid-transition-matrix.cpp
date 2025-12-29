class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool solve(string row) {
        if (row.size() == 1) return true;
        if (memo.count(row)) return memo[row];

        int n = row.size();
        vector<string> nextRows;

        function<void(int, string&)> build = [&](int i, string& next) {
            if (i == n - 1) {
                nextRows.push_back(next);
                return;
            }
            string key = row.substr(i, 2);
            if (!mp.count(key)) return;
            for (char c : mp[key]) {
                next.push_back(c);
                build(i + 1, next);
                next.pop_back();
            }
        };

        string temp;
        build(0, temp);

        for (auto &nr : nextRows) {
            if (solve(nr))
                return memo[row] = true;
        }

        return memo[row] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed)
            mp[s.substr(0,2)].push_back(s[2]);
        return solve(bottom);
    }
};
