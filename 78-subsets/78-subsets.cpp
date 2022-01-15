class Solution {
public:
        void generateSubsets(int index,vector<int>&nums,vector<int>&curr,   vector<vector<int>>& subset){
        subset.push_back(curr);
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            generateSubsets(i+1,nums,curr,subset);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> subset;
        vector<int> curr;
        generateSubsets(0,nums,curr,subset);
        return subset;
    }
    
};