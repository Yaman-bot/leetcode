class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            if(row==n-1 && col==m-1)
                return diff;
            
            for(int i=0;i<4;i++){
                int nbrRow=row+delRow[i];
                int nbrCol=col+delCol[i];
                
                if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol<m){
                    int newEffort=max(abs(heights[nbrRow][nbrCol]-heights[row][col]),diff);
                    if(newEffort<dist[nbrRow][nbrCol]){
                        dist[nbrRow][nbrCol]=newEffort;
                        pq.push({dist[nbrRow][nbrCol],{nbrRow,nbrCol}});
                    }
                }
            }
        }
                                      
        return 0;
    }
};