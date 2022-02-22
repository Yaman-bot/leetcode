class Solution {
public:
  static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[1]==v2[1])
        {
            return v1[0]<v2[0];
        }
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& nums) {
        priority_queue<int>pq;
        sort(nums.begin(),nums.end(),cmp);
        int time=0;
        for(int i=0;i<nums.size();i++)
        {
            //if duration is less than lastday
            if(time+nums[i][0]<=nums[i][1])
            {
                time=time+nums[i][0];
                pq.push(nums[i][0]);
            }
            //swap for a shorter duration course
            else if(!pq.empty()&&pq.top()>nums[i][0])
            {
                time=time-pq.top();
                pq.pop();
                time=time+nums[i][0];
                pq.push(nums[i][0]);
            }
        }
        return pq.size();
    }
};