class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;     
        for(auto &words : sentences) 
        {
            int cnt = 1;    //as numbers of words is 1 greater than number of spaces
            for(auto &word : words) 
            {
                if(word== ' ') 
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};