// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C
typedef long long ll;
class Solution{
    ll MAX(ll a,ll b){
        return a>b?a:b;
    }
    ll MIN(ll a,ll b){
        return a>b?b:a;
    }
    ll SWAP(ll &a,ll &b){
        ll temp = a;
        a=b;
        b=temp;
    }
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    ll max_product=arr[0];
	    ll min_product=arr[0];
	    ll max_of_all=arr[0];
	    
	    for(int i=1;i<n;i++){
	        if(arr[i]<0) SWAP(max_product,min_product);
	        max_product = MAX(arr[i],arr[i]*max_product);
	        min_product = MIN(arr[i],arr[i]*min_product);
	        if(max_product>max_of_all) max_of_all = max_product;
	    }
	    return max_of_all;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends