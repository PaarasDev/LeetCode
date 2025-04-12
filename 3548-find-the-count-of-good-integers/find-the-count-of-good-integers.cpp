class Solution {
public:
    long long factorial(int num) {
        long long result = 1;
        for (int i = 1; i <= num; i++) result *= i;
        return result;
    }

    void generatePalindromes(string& s, int idx, vector<string>& palindromes, int k) {
        if (idx >= (s.length() + 1) / 2) {
            if (stoll(s) % k == 0) palindromes.push_back(s);
            return;
        }

        if (idx != 0) {
            s[idx] = '0';
            s[s.size() - 1 - idx] = '0';
            generatePalindromes(s, idx + 1, palindromes, k);
        }

        for (char c = '1'; c <= '9'; c++) {
            s[idx] = c;
            s[s.size() - 1 - idx] = c;
            generatePalindromes(s, idx + 1, palindromes, k);
        }
    }

    long long countGoodIntegers(int n, int k) {
        vector<string> palindromes;
        string s(n, '0');
        generatePalindromes(s, 0, palindromes, k);

        set<string> patterns;
        for (auto& p : palindromes) {
            vector<int> freq(10, 0);
            for (char c : p) freq[c - '0']++;
            string pat;
            for (int f : freq) pat += (char)('a' + f);
            patterns.insert(pat);
        }

        long long base = factorial(n);
        long long total = 0;

        for (auto& pat : patterns) {
            long long perms = base;
            for (char f : pat) perms /= factorial(f - 'a');

            if (pat[0] != 'a') {
                int zeroCount = pat[0] - 'a' - 1;
                long long zeroPerms = factorial(n - 1);
                for (int i = 1; i < pat.size(); i++) zeroPerms /= factorial(pat[i] - 'a');
                zeroPerms /= factorial(zeroCount);
                perms -= zeroPerms;
            }

            total += perms;
        }

        return total;
    }
};
