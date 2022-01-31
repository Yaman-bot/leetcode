// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
    // code here
        int maxi=0,ans=0;
        vector<int> dp(N);
        for(int i=0;i<N;i++){
            dp[i]=max(mat[0][i],mat[1][i]);
            if(i>=2) {
                maxi=max(maxi,dp[i-2]);
                dp[i]+=maxi;
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends