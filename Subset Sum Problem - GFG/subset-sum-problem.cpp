// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<bool> dp(sum + 1);
        dp[0] = true;

        // process all subsets for all sums
        for (int i = 0; i < N; i++)
        {
            for (int s = sum; s >= arr[i]; s--)
            {
                if (dp[s - arr[i]])
                    dp[s] = true;
            }
        }
        return dp[sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends