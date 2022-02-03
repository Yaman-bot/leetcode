class Solution {
public:
    bool isUgly(int n) {
        if(n < 1) 
            return false;

        vector<int> v = {2,3,5};
        for(int i=0 ; i<v.size(); i++){
             while(n% v[i] == 0)
                n = n/v[i];
        }
           
        if(n == 1)  
            return true;
        else 
            return false;

    }
};