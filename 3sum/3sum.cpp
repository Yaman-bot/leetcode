class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if(nums.size()==0)
            return {};
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // for a moves
        for (int i = 0; i < n- 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int low = i + 1, high = n - 1, sum = 0 - nums[i];

                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[low]);
                        tmp.push_back(nums[high]);
                        res.push_back(tmp);

                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;
                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] < sum)
                        low++;
                    else
                        high--;
                }
            }
        }
        return res;
    }
};