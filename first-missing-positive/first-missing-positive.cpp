class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num:nums)
            s.insert(num);
        
        int k=1;
        for(auto num:nums){
            if(s.find(k)==s.end())
                return k;
            k++;
        }
        return k;
    }
};