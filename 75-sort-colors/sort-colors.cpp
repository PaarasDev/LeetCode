class Solution {
public:

void merge(vector<int>& nums,int l,int mid,int r)
{
    vector<int> ans;
    int left=l;
    int right=mid+1;
    while(left<=mid && right<=r)
    {
        if(nums[left]<=nums[right])
        {
            ans.push_back(nums[left]);
            left++;
        }
       else
        {
            ans.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        ans.push_back(nums[left]);
        left++;
    }
    while(right<=r)
    {
        ans.push_back(nums[right]);
        right++;
    }
    for(int i=0;i<ans.size();i++)
    {
        nums[l+i]=ans[i];
    }
}
void mergeSort(vector<int>& nums,int l,int r)
{
    if(l>=r)
    {
        return ;
    }
    int mid=(l+r)/2;
    mergeSort(nums,l,mid);
    mergeSort(nums,mid+1,r);
    merge(nums,l,mid,r);
}

    void sortColors(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        mergeSort(nums,l,r);
    }
};