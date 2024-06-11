class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for (int i = n - 1; i >= 0;i--){
            int mini = 1e9;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        // Subtracting 1 because of the extra partition at the end of string
        return dp[0] - 1;
    }
};