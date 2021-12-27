class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>m;
        int ans=0;
        for(auto i :jewels){
            m[i] = 0;
        }
        for(auto i :stones){
            if(m.find(i)!=m.end()){
                ans++;
            }
        }
        return ans;
    }
};