class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        vector<vector<string>> ans;
        bool found = false;
        for (auto word : wordList)
        {
            if (word == endWord)
                found = true;
            s.insert(word);
        }
        if (!found)
            return {};
        queue<vector<string>> q;
        q.push({beginWord});
        bool flag=false;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                vector<string> currPath = q.front();
                q.pop();
                string last=currPath.back();
                s.erase(last);
                for (int i = 0; i < last.size(); i++)
                {
                    string temp = last;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if (temp == endWord){
                            currPath.push_back(endWord);
                            ans.push_back(currPath);
                            flag=true;
                            continue;
                        }
            
                        if (s.find(temp) != s.end())
                        {
                            currPath.push_back(temp);
                            q.push(currPath);
                            currPath.pop_back();
                
                        }
                    }
                }
            }
            if(flag)
                break;
        }
        return ans;
    }
};