class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> board,int n, int m){
        if(row<0 || row>=n || col<0 || col>=m)
            return;
        if(board[row][col]=='X' || vis[row][col])
            return;
        vis[row][col]=1;
        dfs(row+1,col,vis,board,n,m);
        dfs(row-1,col,vis,board,n,m);
        dfs(row,col+1,vis,board,n,m);
        dfs(row,col-1,vis,board,n,m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //traverse first and last row
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,n,m);
            }
            //last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board,n,m);
            }
        }

        //traverse first and last col
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,n,m);
            }
            //last col
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};