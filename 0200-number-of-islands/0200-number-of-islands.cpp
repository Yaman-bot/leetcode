class Solution {
public:
    void bfs(int r,int c,vector<vector<int>> &vis,int n,int m,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nbrRow=row+delRow[i];
                int nbrCol=col+delCol[i];
                
                if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol<m &&
                    grid[nbrRow][nbrCol]=='1' && !vis[nbrRow][nbrCol]){
                        q.push({nbrRow,nbrCol});
                        vis[nbrRow][nbrCol]=1;
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1' && !vis[r][c]){
                    ans++;
                    bfs(r,c,vis,n,m,grid);
                }
            }
        }
        return ans;
    }
};