class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        bool increasing = true, decreasing = true;
        for(int i=1; i<a.size(); i++){
            if(a[i] > a[i-1]) 
                decreasing=false;
            if(a[i] < a[i-1]) 
                increasing=false;
            if(!increasing && !decreasing)
                return false;
        }
        return increasing || decreasing;
    }
};