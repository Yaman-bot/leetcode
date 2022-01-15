class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, v, ans);
        return ans;
    }

    void backtrack(int index, vector<int> &nums, vector<int> &v, vector<vector<int>> &ans)
    {
        ans.push_back(v);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            v.push_back(nums[i]);
            backtrack(i + 1, nums, v, ans);
            v.pop_back();
        }
    }
};