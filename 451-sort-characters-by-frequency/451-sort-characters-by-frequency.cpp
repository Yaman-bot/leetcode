class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        for(int i = 0;i<s.length();i++)
            m[s[i]]++;
        
        for(auto &i:m)
            pq.push(make_pair(i.second, i.first));

        while(!pq.empty())
        {
            int num = pq.top().first;
            while(num!=0)
            {
                ans+=pq.top().second;
                num--;
            }
            pq.pop();
        }
        return ans;
    }
};