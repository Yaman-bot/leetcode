class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int leng = a.size() + b.size();
        vector<int> c(leng);
        for(int i=0; i<a.size(); ++i)
            c[i] = a[i];
        
        for(int i=a.size(),j=0; i<leng; ++i)
            c[i] = b[j++];
        
        sort(c.begin(),c.end());
        double ans;
        if(leng % 2 != 0){
            ans = c[leng/2];
        }
        else{
            ans = (double) (c[leng/2] + c[(leng/2) - 1])/2;
        }
        return ans;
    }
    
};