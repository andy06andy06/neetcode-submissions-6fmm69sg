class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());
        stack<int> stk;
        for(int i=0; i<heights.size(); i++){
            while(!stk.empty() && heights[stk.top()]>= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                left[i] = stk.top();
            }
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i=heights.size()-1; i>=0; i--){
            while(!stk.empty() && heights[stk.top()]>= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                right[i] = stk.top();
            }
            stk.push(i);
        }

        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            left[i] = left[i] + 1;
            right[i] = right[i] - 1;
            maxArea = max(maxArea, heights[i] * (right[i]-left[i]+1));
        }
        return maxArea;
    }
};
