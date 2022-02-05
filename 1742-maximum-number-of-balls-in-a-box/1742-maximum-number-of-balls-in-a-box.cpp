class Solution {
public:
    int sums(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n=n/10;  
        }
        return sum;
    }
    int countBalls(int l, int h) {
        unordered_map<int,int> m;
        for(int i=l;i<=h;i++)
        {
            int k=sums(i);
            m[k]++;
        }
        int ans=0;  
        for(auto it: m)
            ans=max(ans,it.second);
        
        return ans;
    }
};