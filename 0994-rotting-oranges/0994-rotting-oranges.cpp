class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis;
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},time});
                }
            }
        }

        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int currTime=q.front().second;
            q.pop();
            time=max(time,currTime);

            for(int i=0;i<4;i++){
                int nbrRow=row+delRow[i];
                int nbrCol=col+delCol[i];
                if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol<m
                 && grid[nbrRow][nbrCol]==1){
                     grid[nbrRow][nbrCol]=2;
                     q.push({{nbrRow,nbrCol},currTime+1});
                 }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;
    }
};