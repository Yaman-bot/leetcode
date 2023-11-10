class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int rowIndex[] = {0, 0, -1, 1}; //right,left,up,down
        int colIndex[] = {1, -1, 0, 0};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int row = x.first.first;
            int col = x.first.second;
            int currDepth = x.second;
            dist[row][col]=currDepth;
            for (int i = 0; i < 4; i++)
            {
                int rowPos = row + rowIndex[i];
                int colPos = col + colIndex[i];
                if (rowPos >= 0 && rowPos < n && colPos >= 0 && colPos < m
                     && !vis[rowPos][colPos])
                {
                    vis[rowPos][colPos]=1;
                    q.push({{rowPos, colPos}, currDepth + 1});
                }
            }

        }
        return dist;
    }
};