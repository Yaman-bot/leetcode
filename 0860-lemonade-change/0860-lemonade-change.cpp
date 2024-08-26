class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(auto b:bills){
            if(b==5)
                five++;
            else if(b==10){
                ten++;
                if(five)
                    five--;
                else 
                    return false;
            }
            else{
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five>=3)
                    five-=3;
                else
                    return false;
            }
        }
        return true;
    }
};