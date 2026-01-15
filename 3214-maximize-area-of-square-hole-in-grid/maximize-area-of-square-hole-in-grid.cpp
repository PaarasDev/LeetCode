class Solution {
public:
    int maxConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int best = 1, cur = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) cur++;
            else cur = 1;
            best = max(best, cur);
        }
        return best + 1;   // gap size = consecutive removals + 1
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = maxConsecutive(hBars);
        int v = maxConsecutive(vBars);
        int side = min(h, v);
        return side * side;
    }
};
