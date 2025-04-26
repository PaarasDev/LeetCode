class Solution {
public:
   int countLargestGroup(int n) {
    vector<int> count(40, 0); // Max possible digit sum for n <= 10^4 is ~36

    for (int i = 1; i <= n; ++i) {
        int sum = 0, num = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        count[sum]++;
    }

    int maxCount = 0;
    for (int c : count) {
        maxCount = max(maxCount, c);
    }

    int res = 0;
    for (int c : count) {
        if (c == maxCount) res++;
    }

    return res;
}
};