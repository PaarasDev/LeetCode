class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long prefix = 0;
    long long min_prefix = 0, max_prefix = 0;

    for (int diff : differences) {
        prefix += diff;
        min_prefix = min(min_prefix, prefix);
        max_prefix = max(max_prefix, prefix);
    }

    long long max_start = lower - min_prefix;
    long long min_start = upper - max_prefix;

    return max(0LL, min_start - max_start + 1);
    }
};