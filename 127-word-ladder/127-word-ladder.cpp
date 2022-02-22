class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool found=false;
        for(auto &word:wordList){
            if(word==endWord)
                found=true;
            s.insert(word);
        }
        
        //if endword is not in wordlist
        if(!found)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty()){
            depth++;
            int sz=q.size();
            while(sz--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        
                        if(temp==curr)
                            continue;
                        if(temp==endWord)
                            return depth+1;
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};