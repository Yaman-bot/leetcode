class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int preSum=0,cnt=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int rem=preSum-k;
            cnt+=mp[rem];
            mp[preSum]+=1;
        }
        return cnt;
    }
};