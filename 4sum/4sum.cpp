class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    int two_sum = nums[left] + nums[right];
                    if (two_sum < temp)
                        left++;
                    else if (two_sum > temp)
                        right--;
                    else
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        res.push_back(v);

                        // Processing duplicates for number 3
                        while (left < right && nums[left] == v[2])
                            left++;
                        // Processing duplicates for number 4
                        while (left < right && nums[right] == v[3])
                            right--;
                    }
                }
                // Processing duplicates for number 2
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            // Processing duplicates for number 1
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};