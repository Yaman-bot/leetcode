class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        for(auto &i:s)
            m[i]++;
        
        for(auto &i:m)
            pq.push({i.second, i.first});

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