class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int m=s.size();
        int count=0;
        for(int i=0,j=0;j<m&&i<n;)
        {  
            if(s[j]>=g[i]){
                count++; 
                 i++;  }
             j++;
        }
         return count;
    }
};