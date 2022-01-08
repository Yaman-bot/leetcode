class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        bool flag=binary_search(nums.begin(),nums.end(),target);
        if(!flag)
            return {-1,-1};
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int second=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};