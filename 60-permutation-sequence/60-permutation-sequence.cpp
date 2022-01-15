class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact*=i;  //factorial of n-1
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans="";
        k=k-1; //for 0 based indexing
        while(true){
            int digit=nums[k/fact];
            ans+=to_string(digit);
            //erasing the digit that has been added to string
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0)
                break;
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};