class Solution {
public:
    bool isSafe(vector<string> &ds,int n,int row,int col){
        //same column check
        for(int i=0;i<row;i++){
            if(ds[i][col]=='Q')
                return false;
        }
        
        //Left diagonal check
        int x=row-1;
        int y=col-1;
        while(x>=0 and y>=0){
            if(ds[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        
        x=row-1,y=col+1;
        //right diagonal check
        while(x>=0 and y<n){
            if(ds[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        
        //can place a queen
        return true;
    }
    void NQ(int row, vector<string> &ds, vector<vector<string>> &ans, int n){
        if(row==n){
            ans.push_back(ds);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(ds,n,row,col)){
                ds[row][col]='Q';
                NQ(row+1,ds,ans,n);
                ds[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds(n, string(n, '.'));
        NQ(0,ds,ans,n);
        return ans;
    }
};