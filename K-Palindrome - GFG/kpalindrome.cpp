// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int start = n; start >= 0; start--)
        {
            for (int end = start + 1; end < n; end++)
            {
                if (s[start] == s[end])
                    dp[start][end] = dp[start + 1][end - 1] + 2;
                else
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
            }
        }
        return dp[0][n - 1];
    }
    
    int kPalindrome(string s, int n, int k)
    {
        // code here
        int lps = longestPalindromeSubseq(s);
        if((n-lps)<=k)
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends