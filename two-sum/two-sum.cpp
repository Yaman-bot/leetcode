class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];

            //if numberToFind is found in map, return them
            if (m.find(numberToFind) != m.end()) {
                result.push_back(m[numberToFind]);
                result.push_back(i);			
                return result;
            }

            //number was not found. Put it in the map.
            m[nums[i]] = i;
        }
        return result;
    }
};