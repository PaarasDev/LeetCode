class Solution {
public:
    vector<int> parent = vector<int>(26);
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[max(px, py)] = min(px, py);
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; ++i)
            parent[i] = i;
        
        for (int i = 0; i < s1.size(); ++i)
            unite(s1[i] - 'a', s2[i] - 'a');
        
        string res = "";
        for (char c : baseStr)
            res += char(find(c - 'a') + 'a');
        
        return res;
    }
};
