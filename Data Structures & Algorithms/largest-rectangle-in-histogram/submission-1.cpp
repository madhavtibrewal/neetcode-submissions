class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack;
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                auto [idx, height] = stack.top();
                stack.pop();
                maxArea = max(maxArea, height * (i - idx));
                start = idx;
            }
            stack.push({start, heights[i]});
        }

        while(!stack.empty()){
            auto [idx, height] = stack.top();
            stack.pop();
            maxArea = max(maxArea, height * (n - idx));
        }

        return maxArea;
    }
};