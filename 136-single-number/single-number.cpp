class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            x=x^nums[i]; //XOR operator will make all elements 0 except the single one as 2^2=0
        }
        return x;
    }
};