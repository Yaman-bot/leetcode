// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string S, string T)
    {
      //Your code here
        vector<vector<int>> dp;
        for(int i=0;i<=S.size();i++)
            dp.push_back(vector<int>(T.size()+1,0));
        
        for(int i=0;i<=S.size();i++)
            dp[i][T.size()] = 1;
            
        for(int j=T.size()-1;j>=0; j--)
        {
            for(int i=S.size()-1; i>=0; i--)
            {
                if(S[i]==T[j])
                    dp[i][j] = (dp[i+1][j+1]+dp[i+1][j])%(1000*1000*1000+7);
                else
                    dp[i][j] = dp[i+1][j];
            }
        }
        
        return dp[0][0];
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends