// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recFuc(string s1 , string s2 , int a , int b ,
    vector<vector<int>> &dp){
        if(dp[a][b] != -1) return dp[a][b];
        else if(a==0) return 0;
        if(s1[a-1] == s2[b-1])
            dp[a][b] =  recFuc(s1 , s2 , a-1 , b-1 , dp) + recFuc(s1 , s2 , a-1 , b , dp);
        else
            dp[a][b] = recFuc(s1 , s2 , a-1 , b , dp);
        return dp[a][b];
    }
    int countWays(string S1, string S2){
        vector<vector<int>> dp(S1.length()+1 , vector<int> (S2.length()+1 , -1));
        dp[0][0] = 1;
        return recFuc(S1 , S2 , S1.length() , S2.length() , dp);
    }
};
// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends