class Solution
{
public:
    void helper(vector<int> &candidates, vector<vector<int>> &res, vector<int> &v,
                int i, int target, int sum)
    {
        if (i == candidates.size())
            return;
        if (sum == target)
        {
            res.push_back(v);
            return;
        }

        // Pick the element
        if (sum > target)
            return;

        v.push_back(candidates[i]);
        // As we can again pick the element therefore don't increment i
        helper(candidates, res, v, i, target, sum + candidates[i]);
        v.pop_back();

        // Don't pick the element
        helper(candidates, res, v, i + 1, target, sum);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;
        helper(candidates, res, v, 0, target, 0);
        return res;
    }
};