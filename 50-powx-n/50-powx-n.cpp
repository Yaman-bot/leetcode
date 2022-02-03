class Solution {
public:
    double solve(double x, int n){
            if(n == 0)
                return 1;

            double ans = solve(x, n/2);
            if(n%2 == 0)
                return ans * ans;
            else
                return x * ans * ans;
    }
    double myPow(double x, int n) {
        if(n < 0)
            return 1 / solve(x, n);
        else
            return solve(x, n);
    }
};