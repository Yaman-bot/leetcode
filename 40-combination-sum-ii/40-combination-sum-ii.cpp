class Solution {
public:
    void findCombinations(int idx,int target,vector<int>& candidates,
                          vector<vector<int>> &ans,vector<int> &ds)
    {
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int j=idx;j<candidates.size();j++){
            if(j>idx && candidates[j]==candidates[j-1])
                continue;
            if (candidates[idx] > target)
                break;
            ds.push_back(candidates[j]);
            findCombinations(j+1,target-candidates[j],candidates,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        findCombinations(0,target,candidates,ans,ds);
        return ans;
    }
};