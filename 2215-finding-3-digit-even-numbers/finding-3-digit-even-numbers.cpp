class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        vector<int> res;
        for (int i = 1; i <= 9; i++) { // hundreds place can't be 0
            if (freq[i] == 0) continue;
            freq[i]--;
            for (int j = 0; j <= 9; j++) { // tens place
                if (freq[j] == 0) continue;
                freq[j]--;
                for (int k = 0; k <= 9; k += 2) { // units place must be even
                    if (freq[k] == 0) continue;
                    int num = i * 100 + j * 10 + k;
                    res.push_back(num);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
