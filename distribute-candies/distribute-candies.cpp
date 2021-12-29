class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int max_types = candyType.size() / 2;
        
        unordered_set<int> s;
        for(int i : candyType)
            s.insert(i);
        
        return s.size() < max_types ? s.size() : max_types;
    }
};