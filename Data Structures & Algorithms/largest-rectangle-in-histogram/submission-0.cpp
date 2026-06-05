class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> bars; // {height, startIndex}

        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int start = i;

            while (!bars.empty() && bars.top().first > h) {
                int poppedHeight = bars.top().first;
                int poppedStart = bars.top().second;
                bars.pop();

                int width = i - poppedStart;
                int area = poppedHeight * width;
                maxArea = max(maxArea, area);

                start = poppedStart;
            }

            bars.push({h, start});
        }

        int n = heights.size();

        while (!bars.empty()) {
            int poppedHeight = bars.top().first;
            int poppedStart = bars.top().second;
            bars.pop();

            int width = n - poppedStart;
            int area = poppedHeight * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};