class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n;
        int rev=temp%10;
        temp/=10;
        while(temp>0)
        {
            rev*=10;
            int a=temp%10;
            rev+=a;
            temp/=10;
        }
        int ans=abs(n-rev);
        return ans;
    }
};