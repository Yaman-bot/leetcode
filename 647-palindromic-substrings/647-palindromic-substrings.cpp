class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans=0;
        
        for (int i = 0; i < n; i++){
            dp[i][i] = true;
            ans++;
        }
        
        for (int start = n; start >= 0; start--)
        {
            for (int end = start + 1; end < n; end++)
            {
                if (s[start] == s[end])
                {
                    if (end - start == 1 || dp[start + 1][end - 1] == true){
                        dp[start][end] = true;
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};