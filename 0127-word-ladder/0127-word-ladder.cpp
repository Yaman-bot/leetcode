class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool found=false;
        for(auto word:wordList){
            if(word==endWord)
                found=true;
            s.insert(word);
        }
        if(!found)
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            //Start the transformation
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                    if(word==endWord)
                        return steps+1;
                }
                word[i]=original;
            }
        }
        return 0;
    }
};