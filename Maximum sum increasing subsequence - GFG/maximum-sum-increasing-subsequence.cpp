// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int msum[n];
	    msum[0] = arr[0];
	    for(int i = 1; i < n; i++)
	    {
	        msum[i] = arr[i];
	        for(int j = 0; j < i; j++)
	        {
	            if(arr[i] > arr[j])
	                msum[i] = max(msum[i], msum[j]+arr[i]);
	        }
	    }
	    
	    return *max_element(msum, msum+n);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends