class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        for(auto ch:words[0])
            m1[ch]++;
        
        for(int i=1;i<words.size();i++){
            string word=words[i];
            for(auto ch:word){
                if(m1.find(ch)!=m1.end() && m1[ch]>0){
                    m1[ch]--;
                    m2[ch]++;
                }
            }
            m1.clear();
            m1=m2;
            m2.clear();
        }
        
        vector<string> res;
        for(auto i:m1){
            int cnt=i.second;
            string s="";
            s+=i.first;
            while(cnt>0){
                res.push_back(s);
                cnt--;
            }
        }
        return res;
    }
};