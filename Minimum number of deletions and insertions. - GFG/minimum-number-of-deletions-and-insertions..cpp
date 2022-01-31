// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int LCS(string x,string y)
       {
           int n=x.length();
           int m=y.length();
           int dp[n+1][m+1];
           for(int i=0;i<=n;i++)
              for(int j=0;j<=m;j++)
                 if(i==0||j==0)
                    dp[i][j]=0;
           //////////////////
           for(int i=1;i<=n;i++)
              for(int j=1;j<=m;j++)
              {
                   if(x[i-1]==y[j-1])
                      dp[i][j]=1+dp[i-1][j-1];
                   else
                      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
              return dp[n][m];
       }
     
    
    public:
    int minOperations(string x, string y) 
    { 
        int lcs=LCS(x,y);
        int del=x.length()-lcs;
        int ins=y.length()-lcs;
        return del+ins;
    } 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends