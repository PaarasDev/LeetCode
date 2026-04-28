class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> array;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                array.push_back(grid[i][j]);
            }
        }
        sort(array.begin(),array.end());
        int check=array[0]%x;
        for(int i=1;i<array.size();i++)
        {
            if(array[i]%x != check)
            {
                return -1;
            }
        }
        int mid= array[array.size()/2];
        int count=0;
        for(auto val:array)
        {
            count+=abs(mid-val)/x;
        }
        return count;

    }
};