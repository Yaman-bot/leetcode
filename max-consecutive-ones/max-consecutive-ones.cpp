class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                maxx=max(cnt,maxx);
            }
            else
                cnt=0;
        }
        return maxx;
    }
};