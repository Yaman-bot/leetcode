class Solution
{
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n, vector<int> &dp, string &s)
    {
        if(i==n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int mini = 1e9;
        for (int j = i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+f(j+1,n,dp,s);
                mini = min(mini,cost);
            }
        }
        dp[i] = mini;
        return dp[i];
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        //Subtracting 1 because of the extra partition at the end of string
        return f(0, n, dp,s)-1;
    }
};