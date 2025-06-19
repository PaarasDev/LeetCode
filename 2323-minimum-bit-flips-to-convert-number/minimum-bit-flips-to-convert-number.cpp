class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int res=0;
        
        while(n>0){
           if(n%2==1)
          { res++; }
        n/=2;
        }
        return res;
    }
};