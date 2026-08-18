class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int ele=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int width=(nse-pse-1);
                int area=ele*width;
                maxarea=max(maxarea,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            int width=(nse-pse-1);
            int area=width*ele;
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};
