class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> distCount;

            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dist = dx * dx + dy * dy;  // squared distance (no need for sqrt)

                distCount[dist]++;
            }

            for (auto& [_, count] : distCount) {
                res += count * (count - 1);  // ordered pairs (j, k)
            }
        }

        return res;
    }
};
