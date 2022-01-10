class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftPrefix,rightPrefix;
        int left=1,right=1;
        for(int i=0;i<nums.size();i++){
            left*=nums[i];
            leftPrefix.push_back(left);
        }
        for(int i=nums.size()-1;i>=0;i--){
            right*=nums[i];
            rightPrefix.push_back(right);
        }
        reverse(rightPrefix.begin(),rightPrefix.end());
        vector<int> ans;
        ans.push_back(rightPrefix[1]);
        for(int i=1;i<nums.size()-1;i++){
            ans.push_back(leftPrefix[i-1]*rightPrefix[i+1]);
        }
        ans.push_back(leftPrefix[leftPrefix.size()-2]);
        return ans;
    }
};