class Solution {
public:
    int uniquePaths(int m, int n) {
                int N=m+n-2;
        int r=min(m,n)-1;
        double res=1;
        for(int i=1;i<=r;i++)
        {
            res*=(N-i+1);
            res/=i;
        }
        return (int)res;
    }
};