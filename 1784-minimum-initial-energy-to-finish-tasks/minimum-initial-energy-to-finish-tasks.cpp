class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans=0,curr=0;
    sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
    return (a[1] - a[0]) > (b[1] - b[0]);
});
    for(auto it : tasks)
    {
        if(curr<it[1])
        {
            ans+=abs(it[1]-curr);
            curr=it[1];

        }
        curr-=it[0];
    }
    return ans;
    }
};