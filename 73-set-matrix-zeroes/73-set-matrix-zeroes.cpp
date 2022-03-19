class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<bool> row(n,false);
        vector<bool> col(m,false);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(row[i]){
                for(int k=0;k<m;k++)
                    matrix[i][k]=0;
            }
        }
        
        for(int i=0;i<m;i++){
            if(col[i]){
                for(int k=0;k<n;k++)
                    matrix[k][i]=0;
            }
        }
        
    }
    
};