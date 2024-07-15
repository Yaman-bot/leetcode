class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        if(n==1) return 1;
        dist[0][0]=1;
        q.push({1,{0,0}});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int wt=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            if(row==n-1 && col==n-1)
                return dist[row][col];
            
            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol=-1;delCol<=1;delCol++){
                    int nbrRow=row+delRow;
                    int nbrCol=col+delCol;
                    
                    if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol<n && grid[nbrRow][nbrCol]==0){
                        if(dist[nbrRow][nbrCol]>wt+1){
                            dist[nbrRow][nbrCol]=wt+1;
                            q.push({dist[nbrRow][nbrCol],{nbrRow,nbrCol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};