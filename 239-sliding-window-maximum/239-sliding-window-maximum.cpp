class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        
        //We have to process first k elements separtely
        deque<int> Q(k);
        int i;
        for(i=0;i<k;i++){

            while(!Q.empty() &&nums[i]>nums[Q.back()]){
                Q.pop_back();
            }
            Q.push_back(i);

        }
        //Process the remaining elements 
        for(;i<n;i++){
            ans.push_back(nums[Q.front()]);

            //1. Remove the elements which are not the part of the window(Contraction)
            while((!Q.empty() && (Q.front()<=i-k))){
                Q.pop_front();
            }

            //2. Remove the elements which are not useful and are in window
            while(!Q.empty() && nums[i]>=nums[Q.back()]){
                Q.pop_back();   
            }

            //3. Add the new elements(Expansion)
            Q.push_back(i);
        }

        ans.push_back(nums[Q.front()]);
        return ans;
    }
};