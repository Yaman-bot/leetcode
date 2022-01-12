class Solution {
public:
    
    bool canPlace(vector<vector<char>>& board,int i,int j,int n,char number){
        for(int x=0;x<n;x++){
            //Row and Col Check
            if(board[i][x]==number || board[x][j]==number){
                return false;
            }
        }

        int rn=sqrt(n);
        int sx=(i/rn)*rn;
        int sy=(j/rn)*rn;

        //Subgrid check
        for(int x=sx;x<sx+rn;x++){
            for(int y=sy;y<sy+rn;y++){
                if(board[x][y]==number){
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board,int i,int j,int n){
        //Base Case
        if(i==n)
            return true;

        //Case Row End
        if(j==n)
            return solve(board,i+1,0,n);

        //Skip the prefilled cells
        if(board[i][j]!='.')
            return solve(board,i,j+1,n);

        //Recursive Case
        //Fill current cell with possible options
        for(int number=1;number<=n;number++){
            if(canPlace(board,i,j,n,'0'+number)){
                //Assume 
                board[i][j]='0'+number;

                bool couldWeSolve=solve(board,i,j+1,n);
                if(couldWeSolve)
                    return true;
            }
        }

        //Backtracking
        board[i][j]='.';
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        bool ans=solve(board,0,0,n);
    }
};