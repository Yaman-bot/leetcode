class Solution {
public:
    int largestHistogram(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ind=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1 : st.top();
                int area=arr[ind]*(nse-pse-1);
                ans=max(ans,area);
            }
            st.push(i);
        }
        while(!st.empty()){
                int ind=st.top();
                st.pop();
                int nse=n;
                int pse=st.empty() ? -1 : st.top();
                int area=arr[ind]*(nse-pse-1);
                ans=max(ans,area);
            }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> pSum(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1')
                    sum++;
                if(matrix[i][j]=='0')
                    sum=0;
                pSum[i][j]=sum;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int rowArea=largestHistogram(pSum[i]);
            ans=max(ans,rowArea);
        }
        return ans;
    }
};