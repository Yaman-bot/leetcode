// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int isPossiblePalindrome(string s, int K)
	{
	    int n = s.size();
	    string s2;
	    for(int i=n-1; i>=0; i--) s2.push_back(s[i]);
	    return (n-lcs(s, s2))<=K;
	}
	int lcs(string& s1, string& s2) {
	    int n = s1.size();
	    int dp[n+1][n+1];
	    for(int i=0; i<=n; i++) {
	        for(int j=0; j<=n; j++) {
	            if(i==0 || j==0) dp[i][j] = 0;
	            else if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
	        }
	    }
	    return dp[n][n];
	}
	  
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int k;
        cin >> k;

       
	    Solution ob;
	    cout << ob.isPossiblePalindrome(s, k) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends