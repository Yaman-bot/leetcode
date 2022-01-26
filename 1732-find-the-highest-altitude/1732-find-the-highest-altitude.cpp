class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0 ;
        vector<int> v;
        for(int i = 0 ; i<gain.size() ; i++){
            sum+=gain[i];
            v.push_back(sum);
        }
        int x = *max_element(v.begin() , v.end());
        if(x>0)
            return x;
        return 0;
    }
};