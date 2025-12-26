class Solution {
public:
    int bestClosingTime(string customers) {
        int score = 0, minScore = 0, ans = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'N') score++;
            else score--;

            if (score < minScore) {
                minScore = score;
                ans = i + 1;
            }
        }
        return ans;
    }
};
