class Solution {
public:
    void combination(vector<vector<int>> &res,vector<int> &sol,int k, int n){
        if(sol.size()==k && n==0){
            res.push_back(sol);
            return;
        }
        
        for(int i=sol.empty() ? 1 : sol.back()+1;i<=9;i++){
            if(i>n)
                break;
            sol.push_back(i);
            combination(res,sol,k,n-i);
            sol.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        combination(res, sol, k, n);
        return res;
    }
};