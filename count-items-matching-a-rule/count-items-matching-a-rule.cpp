class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for(int i = 0; i< items.size(); i++){
                if(ruleKey == "type"){
                    string val =  items[i][0];
                    if(ruleValue == val){
                        count++;
                    }
                }
                
                else if (ruleKey == "color"){
                    string val =  items[i][1];
                  //  cout << val << endl;
                    if(ruleValue == val){
                        count++;
                    }
                }
                else if(ruleKey == "name"){
                    string val =  items[i][2];
                    if(ruleValue == val){
                        count++;
                    }
            }
        }
        return count;
        
    }
};