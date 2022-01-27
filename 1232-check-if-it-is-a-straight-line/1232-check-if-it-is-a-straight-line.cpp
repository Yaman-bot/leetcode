class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)
            return true;
        
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        
        for(int i=2;i<coordinates.size();i++){
            int x3= coordinates[i][0];
            int y3= coordinates[i][1];
            
            //If slopes are not equal then not a straight line
            if ((y3 - y2) * (x2 - x1) != (y2 - y1) * (x3 - x2))
                return false;
        }
        return true;
    }
};