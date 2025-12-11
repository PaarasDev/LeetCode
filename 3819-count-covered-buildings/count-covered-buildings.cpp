class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows, cols;

        // Fill row and column maps
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }

        // Sort each row and column list for binary search
        for (auto &p : rows) sort(p.second.begin(), p.second.end());
        for (auto &p : cols) sort(p.second.begin(), p.second.end());

        int ans = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // Check LEFT in row x → smallest y < current y
            auto &r = rows[x];
            bool hasLeft  = lower_bound(r.begin(), r.end(), y) != r.begin();

            // Check RIGHT in row x → exists element > current y
            bool hasRight = (upper_bound(r.begin(), r.end(), y) != r.end());

            // Check ABOVE in column y → exists x' < x
            auto &c = cols[y];
            bool hasUp    = lower_bound(c.begin(), c.end(), x) != c.begin();

            // Check BELOW in column y → exists x' > x
            bool hasDown  = (upper_bound(c.begin(), c.end(), x) != c.end());

            if (hasLeft && hasRight && hasUp && hasDown)
                ans++;
        }

        return ans;
    }
};
