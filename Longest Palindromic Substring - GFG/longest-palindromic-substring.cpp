// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int dp[1001][1001];
        int maxLength = INT_MIN;
        int n = s.size();
        string s2(s.rbegin(), s.rend());
        int fStart; // final start index

        for(int i =0; i <=n;i++)
        {
            for(int j =0; j<=n;j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for(int i =1; i <=n;i++)
        {
            for(int j =1; j<=n;j++)
            {
                if(s[i-1] == s2[j-1] )
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
                
                if(maxLength < dp[i][j])
                {
                    // get substring from reverse string 
                    // resverse it
                    // it should match with substring of actual string
                    
                    // dp[i][j] is possible max length of palindrom; lets call it currMaxLength
                    
                    // i-1 is end of actual string.
                    // end - currMaxLength + 1 is start of actual string
                    int start = (i-1)-dp[i][j] + 1;
                    
                    // j-1 is end of reverse string; lets call it rend.
                    // rend- currMaxLength +1 is start of reverse string; lets call it rstart
                    int rstart = (j-1)-dp[i][j] + 1;
                    
                    // (n-1) - rend should match with start
                    // (n-1) - rstart should match with end
                    int cstart = (n-1) - rstart;
                    if(cstart == (i-1) && (n-1)-(j-1) ==start)
                    {
                        maxLength = dp[i][j];
                        fStart = (i-1)-dp[i][j] + 1;
                    }                  
                }
            }
        }
        
        return s.substr(fStart,maxLength);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends