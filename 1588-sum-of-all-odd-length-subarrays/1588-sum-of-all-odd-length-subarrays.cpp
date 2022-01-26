class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> preSum(n+1);
        
        preSum[0] = 0;
        for(int i = 0; i < arr.size(); i++) {
            preSum[i+1] = arr[i] + preSum[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j += 2) {
                if(j == i) 
                    ans += arr[i];
                else 
                    ans += preSum[j+1] - preSum[i];
            }
        }
        return ans;
    }
};