class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> m;
        vector<int> indegree(numCourses, 0);
        for(auto x:prerequisites){
            m[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans++;
            for(auto nbr:m[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        return ans==numCourses;
    }
};