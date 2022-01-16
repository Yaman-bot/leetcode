class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        pq.push(nums[i]);
        
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            return ((a-1)*(b-1));
        }
        return 0;
    }
};