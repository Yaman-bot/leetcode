#define pp pair<int,int> 
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        //store the k largest elements of the array 
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            if(pq.size()>k)
                pq.pop();
        }
        
        
		// in the following heap the first element of the pair is the index and the second element is the array element itself
        priority_queue<pp,vector<pp>,greater<pp>> pq2;
        while(!pq.empty())
        {
            pq2.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        
        
        vector<int>ans;
        while(!pq2.empty())
        {
            ans.push_back(pq2.top().second);
            pq2.pop();
        }
        

        return ans;
    }
};